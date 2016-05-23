#include "SentioD2D.h"
#include "Application.h"

namespace DXLib
{
	Application::Application(void)
		: _isRunning(false), _hInstance(nullptr), _hWnd(nullptr), _appCaptionMode(AppCaptionMode::NONE)
	{
		Singleton::_Overwrite(this);

		memset(&_renderingInterval, 0, sizeof(LARGE_INTEGER));
		_resourceRootPath.clear();
	}

	Application::~Application(void)
	{
	}

	bool Application::Initialize(const std::string& resourceRootPath, const std::string& configDataPath)
	{
		this->_resourceRootPath = resourceRootPath;

		XMLSerializer* serializer = XMLSerializer::Load(ExtendString::Format("%s/%s", _resourceRootPath.c_str(), configDataPath.c_str()).c_str());

		return _OnInitialize();
	}

	int Application::Run(void)
	{
		return 0;

		LARGE_INTEGER last;
		LARGE_INTEGER now;

		QueryPerformanceCounter(&last);
		auto director = Director::Create();

		while (true)
		{
			QueryPerformanceCounter(&now);

			if (now.QuadPart - last.QuadPart > _renderingInterval.QuadPart)
			{
				last.QuadPart = now.QuadPart - (now.QuadPart % _renderingInterval.QuadPart);

				director->Run();
			}
			else
			{
				Sleep(1);
			}

		}

		director->Destroy();

		return 0;
	}

	void Application::SetRenderingFrame(float frame)
	{
		float interval = 1.0f / frame;
		LARGE_INTEGER frequency;
		QueryPerformanceFrequency(&frequency);
		_renderingInterval.QuadPart = (LONGLONG)(interval * frequency.QuadPart);
	}


	void Application::ShowCursor(bool isShow)
	{
		int cursorCount = 0;

		/**
		@note :
			WINAPI::ShowCursor(bool) =>
			true를 넘기면 CursorCount를 1씩 증가시키고, 0이상이라면 출력
			false를 넘기면 CursorCount를 1씩 감소시키고, 0미만이라면 미출력

		*/

		if (isShow)
		{
			do
			{
				cursorCount = ::ShowCursor(isShow);
			} while (cursorCount < 0);
		}
		else
		{
			do
			{
				cursorCount = ::ShowCursor(isShow);
			} while (cursorCount > -1);
		}
	}

	LRESULT CALLBACK _WinProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
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

				/*if (!IsRectEmpty())
					ClipCursor(&_rect);*/
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
