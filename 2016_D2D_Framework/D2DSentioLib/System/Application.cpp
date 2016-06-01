#include "SentioD2D.h"
#include "Application.h"

namespace DXLib
{
	Application::Application(void)
		: _isReplaceData(false), _isRunning(false),
		_windowCaption(ExtendString::EMPTY), 
		_resourceRootPath(ExtendString::EMPTY),
		_configDataPath(ExtendString::EMPTY),
		_appInstanceHandler(nullptr), _winHandler(nullptr), _iconHandler(nullptr)
	{
		Singleton::_Overwrite(this);

		memset(&_renderingInterval, 0, sizeof(LARGE_INTEGER));
	}

	Application::~Application(void)
	{
		if (_appInstanceHandler == nullptr)
			return;

		_appInstanceHandler = nullptr;

		if (_iconHandler != nullptr)
		{
			if (false == ::DestroyIcon(_iconHandler))
				DWORD dwErrCode = GetLastError();
		}

		if (_isReplaceData)
			this->Serialize(ExtendString::Format("%s/%s", _resourceRootPath.c_str(), _configDataPath.c_str()).c_str());
	}

	bool Application::Initialize(const std::string& resourceRootPath, const std::string& configDataPath,
		OPTIONAL HINSTANCE appInstanceHandler)
	{
		this->_resourceRootPath = resourceRootPath;
		this->_configDataPath = configDataPath;

		if (false == Deserialize(ExtendString::Format("%s\\%s", _resourceRootPath.c_str(), _configDataPath.c_str()).c_str()))
			return false;

		_isReplaceData = true;

		if (false == _CreateWindow((nullptr == appInstanceHandler) ? GetModuleHandle(nullptr) : appInstanceHandler))
			return false;

		auto director = Director::Create();
		if (false == director->Initialize(_winHandler))
		{
			director->Destroy();
			return false;
		}

		return _OnInitialize();
	}

	int Application::Run(void)
	{
		if (_appInstanceHandler == nullptr)
			return 0;

		this->_isRunning = true;

		LARGE_INTEGER performanceFrequency;
		QueryPerformanceFrequency(&performanceFrequency);

		LARGE_INTEGER last;
		LARGE_INTEGER now;

		QueryPerformanceCounter(&last);
		
		Director* director = Director::Instance();

		while (_isRunning)
		{
			QueryPerformanceCounter(&now);
			LONGLONG delta = now.QuadPart - last.QuadPart;

			if (delta > _renderingInterval.QuadPart)
			{
				last.QuadPart = now.QuadPart - (now.QuadPart % _renderingInterval.QuadPart);

				MSG msg = { 0 };
				if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
				{
					if (msg.message == WM_QUIT)
						break;

					if (!TranslateAccelerator(_winHandler, nullptr, &msg))
					{
						TranslateMessage(&msg);
						DispatchMessage(&msg);
					}
				}

				float elapsedTime = delta / (float)performanceFrequency.QuadPart;
				_UpdateWindowCaption(elapsedTime);

				if (false != director->BeginFrame(elapsedTime))
				{
					director->DrawFrame();
					director->EndFrame();
				}
			}
		}

		director->Destroy();
		director = nullptr;

		return 0;
	}

	void Application::SetRenderingFrame(float frame)
	{
		float interval = 1.0f / frame;
		LARGE_INTEGER performanceFrequency;
		QueryPerformanceFrequency(&performanceFrequency);
		_renderingInterval.QuadPart = (LONGLONG)(interval * performanceFrequency.QuadPart);
	}

	void Application::ShowCursor(bool isShow)
	{
		/**
		@note :
			WINAPI::ShowCursor(bool)
				パラメータにtrueを渡せば、カウントを1ずつ増加させ、 0以上になると出力します。
				falseを渡せば、カウントを1ずつ減らし、 0未満になると、出力しません。
		*/
		int cursorCount = 0;
		
		if (isShow)
		{
			do { cursorCount = ::ShowCursor(isShow); } while (cursorCount < 0);
		}
		else
		{
			do { cursorCount = ::ShowCursor(isShow); } while (cursorCount > -1);
		}
	}

	//#########################################################################
#pragma region Serialize Function
	bool Application::Serialize(const char* filePath)
	{
		XMLSerializer* serializer = new XMLSerializer(filePath);

		if (false == Serialize(serializer))
			return serializer->Close();

		serializer->Save();

		return serializer->Close();
	}
	bool Application::Serialize(XMLSerializer* serializer)
	{
		serializer->Write("Data", _data);

		return true;
	}
	bool Application::Deserialize(const char* filePath)
	{
		XMLSerializer* serializer = XMLSerializer::Load(filePath);

		this->Deserialize(serializer);

		return serializer->Close();
	}
	bool Application::Deserialize(XMLSerializer* serializer)
	{
		serializer->Read("Data", _data);

		return true;
	}
#pragma endregion
	//#########################################################################

	bool Application::_CreateWindow(HINSTANCE appInstanceHandler)
	{
		assert(appInstanceHandler != nullptr, "Passed appInstanceHandler is null");
		_appInstanceHandler = appInstanceHandler;
		
		RECT userWindowRect;
		GetWindowRect(::GetDesktopWindow(), &userWindowRect);

		_iconHandler = (_data.IsShowingCaptionMode(AppCaptionMode::ICON) && _data.IsEmptyIconPath() == false)
			? ExtractIcon(_appInstanceHandler, ExtendString::Format("%s\\%s", _resourceRootPath.c_str(), _data.GetIconPath()).c_str(), 0)
			: nullptr;

		const char* caption = _data.GetCaption();

		WNDCLASS wndClass;
		wndClass.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
		wndClass.lpfnWndProc = _WinProc;
		wndClass.cbClsExtra = 0;
		wndClass.cbWndExtra = 0;
		wndClass.hInstance = appInstanceHandler;
		wndClass.hIcon = _iconHandler;
		wndClass.hCursor = LoadCursor(nullptr, IDC_ARROW);
		wndClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
		wndClass.lpszMenuName = nullptr;
		wndClass.lpszClassName = caption;

		if (false == RegisterClass(&wndClass))
			return false;

		Rect clientRectCustom = _data.appWindowRect;
		clientRectCustom.origin = Vector2::Zero;
		RECT clientWinRect = clientRectCustom;

		DWORD style;
		if (_data.useFullScreenMode)
		{
			style = WS_POPUP;
		}
		else
		{
			_data.useTitleBar = true;

			int screenWidth = ExtendMath::GetRectWidth(userWindowRect);
			int screenHeight = ExtendMath::GetRectHeight(userWindowRect);

			if (_data.appWindowRect.size.width >= screenWidth)
			{
				_data.useTitleBar = false;
				_data.appWindowRect.size.width = min(_data.appWindowRect.size.width, screenWidth);
			}

			_data.appWindowRect.size.width = min(_data.appWindowRect.size.width, screenHeight);

			if (_data.useTitleBar)
			{
				style = WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX;
			}
			else
			{
				style = WS_POPUP;
				_data.appWindowRect.origin.x = (screenWidth / 2) - (_data.appWindowRect.size.width / 2);
				_data.appWindowRect.origin.y = (screenHeight / 2) - (_data.appWindowRect.size.height / 2);
			}
		}


		AdjustWindowRect(&clientWinRect, style, false);

		_winHandler = CreateWindow(
			caption,
			caption,
			style,
			_data.appWindowRect.origin.x,
			_data.appWindowRect.origin.y,
			ExtendMath::GetRectWidth(clientWinRect),
			ExtendMath::GetRectHeight(clientWinRect),
			nullptr,
			nullptr,
			appInstanceHandler,
			nullptr);

		if (false == _winHandler)
			return false;

		ShowWindow(_winHandler, SW_SHOW);
		UpdateWindow(_winHandler);

		return true;
	}

	void Application::_UpdateWindowCaption(float elapsedTime)
	{
		/**
		@note :
			アプリケーションのパフォーマンスの為に、
			下の関数の呼び出しに任意のインターバルを置きます。

			SetWindowText && _data.GetCaption
		*/

		const int UPDATE_INTERVAL = 100;
		static int count = 0;

		++count;
		if (count < UPDATE_INTERVAL)
			return;

		count = 0;

		float frameRate = 1.0f / elapsedTime;
		SetWindowText(_winHandler, _data.GetCaption(frameRate, elapsedTime));
	}

	LRESULT CALLBACK Application::_WinProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
	{

		Application* instance = Application::Instance();

		switch (Msg)
		{
		case WM_ACTIVATE:
		{
			if (LOWORD(wParam) == WA_INACTIVE)
			{
				ClipCursor(0);
			}
			else
			{
				RECT rc = const_cast<Rect&>(instance->GetClippingRect());

				if (!IsRectEmpty(&rc))
					ClipCursor(&rc);
			}
		}
		break;
		case WM_SYSCOMMAND:
		{
		}
		break;
		case WM_MOUSEMOVE:
		{
		}
		break;
		case WM_MOUSEWHEEL:
		{
		}
		break;
		case WM_KEYDOWN:
		{
			if (wParam == VK_ESCAPE)
				PostQuitMessage(0);
		}
		break;
		case WM_DESTROY:
		{
			PostQuitMessage(0);
		}
		break;
		}

		LRESULT result = 0;

		if (result == 0)
			result = DefWindowProc(hWnd, Msg, wParam, lParam);

		return result;
	}
}
