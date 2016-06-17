#pragma once

#define D2DRenderTarget SentioD2DLib::Director::Instance()->GetRenderTarget()

#ifndef __SENTIO_D2DLIB_DIRECTOR_H__
#define __SENTIO_D2DLIB_DIRECTOR_H__

/**
@namespace SentioD2DLib
@brief  Direct2Dのライブラリーをなすコンテンツ達の集まり
*/
namespace SentioD2DLib
{
	class SceneManager;

	/**
	@class Director
	@brief アプリケーションの下で全般を管理するクラス
	*/
	class Director sealed : public Singleton<Director>
	{
	SL_CONSTRUCTOR_ACCESS_LEVEL:
		Director(void);
		virtual~Director(void) override;

	public:
		bool Initialize(const HWND hWnd);
		void Release(void);

		/** 毎フレームの始まりを知らせる関数*/
		bool BeginFrame(float deltaTime);
		/** 毎フレームのレンダリングの関数*/
		void DrawFrame(void);
		/** 毎フレームの終わりを知らせる関数*/
		void EndFrame(void);
		
		inline __int64	FrameCount(void) { return _accumFrameCount; }
		inline float	Time(void) { return _accumDeltaTime; }
		inline float	DeltaTime(void) { return _deltaTime; }
		inline ID2D1HwndRenderTarget* GetRenderTarget(void) const { return _renderTarget; }
	protected:
		bool _CreateD2DDevice(const HWND hWnd);

	private:
		__int64					_accumFrameCount;
		float					_deltaTime;
		float					_accumDeltaTime;
		SceneManager*			_sceneManager;
		ID2D1HwndRenderTarget*	_renderTarget;

		PtrPropertyReadonly(ID2D1Factory, _d2dFactory, D2DFactory);
	};

}

#endif //!__SENTIO_D2DLIB_DIRECTOR_H__