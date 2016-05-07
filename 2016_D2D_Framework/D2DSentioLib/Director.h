#pragma once


/**
@namespace DXLib
@brief  Direct2Dのライブラリーをなすコンテンツ達の集まり
*/
namespace DXLib
{
	class Director sealed : public Singleton<Director>
	{
	SL_CONSTRUCTOR_ACCESS_LEVEL:
		Director(void)
			: _d2dFactory(nullptr), _renderTarget(nullptr)
		{

		}
		~Director(void)
		{
			this->Release();
		}

	public:
		bool Initialize(const HWND hWnd);
		void Release(void);

		void Run(void);

		bool BeginFrame(void);
		void EndFrame(void);
		

	protected:
		bool _CreateD2DDevice(const HWND hWnd);;
	private:
		PROPERTY_GET(ID2D1Factory*, _d2dFactory, D2DFactory);
		PROPERTY_GET(ID2D1HwndRenderTarget*, _renderTarget, RenderTarget);
	};

}
