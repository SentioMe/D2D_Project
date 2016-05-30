#include "SentioD2D.h"
#include "Director.h"


namespace DXLib
{
	Director::Director(void)
			: _d2dFactory(nullptr), _renderTarget(nullptr),
		_accumFrameCount(0), _deltaTime(0.0f), _accumDeltaTime(0.0f)
	{

	}
	Director::~Director(void)
	{
		this->Release();
	}

	bool Director::Initialize(const HWND hWnd)
	{
		if (false == this->_CreateD2DDevice(hWnd))
			return false;

		return true;
	}
	void Director::Release(void)
	{
		SAFE_RELEASE(_renderTarget);
		if (_d2dFactory != nullptr)
		{
			ULONG ulMsg = _d2dFactory->Release();
			assert(ulMsg == 0 && "Memory Error! There are objects that have not been deallocated in the objects allocated in the D2D factory");
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

	}

	void Director::EndFrame(void)
	{
		this->_renderTarget->EndDraw();
	}


	bool Director::_CreateD2DDevice(const HWND hWnd)
	{
		assert(hWnd != nullptr && "Device Error : You didn't pass a handle by window");

		
		if (FAILED(D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &this->_d2dFactory)))
		{
			SAFE_RELEASE(_d2dFactory);
			assert("Device Error : Failed to create a factory");

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
			assert("Device Error! Failed to create a render target");

			return false;
		}


		return true;
	}

}