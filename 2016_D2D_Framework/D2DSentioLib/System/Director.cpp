#include "SentioD2D.h"
#include "Director.h"


namespace SentioD2DLib
{
	Director::Director(void)
		: _d2dFactory(nullptr), _renderTarget(nullptr), _sceneManager(nullptr),
		_accumFrameCount(0), _deltaTime(0.0f), _accumDeltaTime(0.0f)
	{
		LOG("Create a instacne of Director");
	}
	Director::~Director(void)
	{
		this->Release();
		LOG("Destroy a instacne of Director");
	}

	bool Director::Initialize(const HWND hWnd)
	{
		if (false == this->_CreateD2DDevice(hWnd))
			return false;

		_sceneManager = SceneManager::Create();

		return true;
	}
	void Director::Release(void)
	{
		_sceneManager->Destroy();
		_sceneManager = nullptr;

		SAFE_RELEASE(_renderTarget);
		if (_d2dFactory != nullptr)
		{
			ULONG message = _d2dFactory->Release();
			assert(message == 0 && "There are objects that have not been deallocated in the objects allocated in the D2D factory");
		}
		
		_d2dFactory = nullptr;
	}

	bool Director::BeginFrame(float deltaTime)
	{
		this->_renderTarget->BeginDraw();
		this->_renderTarget->Clear(D2D1::ColorF(D2D1::ColorF::White));

		_deltaTime = deltaTime;
		_accumDeltaTime += deltaTime;
		++_accumFrameCount;

		return true;
	}

	void Director::DrawFrame(void)
	{
		_sceneManager->Update(_deltaTime);
	}

	void Director::EndFrame(void)
	{
		this->_renderTarget->EndDraw();
	}


	bool Director::_CreateD2DDevice(const HWND hWnd)
	{
		assert(hWnd != nullptr && "Passed window handle is null");

		
		if (FAILED(D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &this->_d2dFactory)))
		{
			SAFE_RELEASE(_d2dFactory);
			assert("Failed to create a factory");

			return false;
		}


		RECT rect;
		::GetClientRect(hWnd, &rect);
		D2D1_SIZE_U stSize = D2D1::SizeU(ExtendMath::GetRectWidth(rect), ExtendMath::GetRectHeight(rect));

		if (FAILED(this->_d2dFactory->CreateHwndRenderTarget(
			D2D1::RenderTargetProperties(),
			D2D1::HwndRenderTargetProperties(hWnd, stSize),
			&this->_renderTarget)))
		{
			SAFE_RELEASE(_renderTarget);
			SAFE_RELEASE(_d2dFactory);
			assert("Failed to create a render target");

			return false;
		}


		return true;
	}

}