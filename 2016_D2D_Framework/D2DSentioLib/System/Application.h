#pragma once


#ifndef __DXLIB_APPLICATION_H__
#define __DXLIB_APPLICATION_H__
/**
@namespace DXLib
@brief  Direct2Dのライブラリーをなすコンテンツ達の集まり
*/
namespace DXLib
{
#define DEFAULT_FRAME 60.0f

	/**
	@class Application
	@brief ライブラリで提供される拡張可能なアプリケーションの原型
	*/
	class Application :
		public Singleton<Application>, public IXMLSerializable
	{
	SL_CONSTRUCTOR_ACCESS_LEVEL:
		Application(void);
		virtual~Application(void) override;

	public:
		bool Initialize(const std::string& resourceRootPath, const std::string& configDataPath,
			OPTIONAL HINSTANCE appInstanceHandler = nullptr);

		int Run(void);

		/** 伝達されたフレームの値でレンダリングのインターバルを調整します。*/
		void SetRenderingFrame(float frame = DEFAULT_FRAME);
		/** マウスのカーソルの出力かどうかを指定します。*/
		void ShowCursor(bool isShow);

		bool IsRunning(void){ return _isRunning; }
		void Stop(void){ _isRunning = false; }

		/** 指定された情報をトップキャプションに出力するようにします。*/
		inline void ShowCaptionMode(AppCaptionMode mode)
		{
			_data.SetCaptionMode(mode, true);
		}
		/** 指定された情報をトップキャプションに出力しないようにします。*/
		inline void UnshowCaptionMode(AppCaptionMode mode)
		{
			_data.SetCaptionMode(mode, false);
		}
		/** トップキャプションに出力される情報のうち、その情報があるか確認します。*/
		inline bool IsShowingCaptionMode(AppCaptionMode mode)
		{
			return _data.IsShowingCaptionMode(mode);
		}
		

//#########################################################################
#pragma region Serialize Function
		bool Serialize(const char* filePath) override;
		bool Serialize(XMLSerializer* serializer) override;
		bool Deserialize(const char* filePath) override;
		bool Deserialize(XMLSerializer* serializer) override;
#pragma endregion
//#########################################################################

	private:
		static LRESULT CALLBACK _WinProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
		
		bool _CreateWindow(HINSTANCE appInstanceHandler);
		/** トップキャプションを更新します。*/
		void _UpdateWindowCaption(float elapsedTime);
	protected:
		/** 継承したクラスでオーバーライド可能な初期化の関数*/
		virtual bool _OnInitialize(void){ return true; }

	private:
		std::string		_configDataPath;
		bool			_isReplaceData;
	protected:
		bool			_isRunning;
		LARGE_INTEGER	_renderingInterval;
		std::string		_windowCaption;
		ApplicationData _data;
		
		PropertyReadonly(std::string, _resourceRootPath, ResourceRootPath);
		PropertyReadonly(Rect, _clippingRect, ClippingRect);

		PropertyReadonly(HINSTANCE, _appInstanceHandler, AppInstanceHandler);
		PropertyReadonly(HWND, _winHandler, WinHandler);
		PropertyReadonly(HICON, _iconHandler, IconHandler);
	};

}

#endif //!__DXLIB_APPLICATION_H__