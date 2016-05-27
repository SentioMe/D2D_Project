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

	class Application :
		public Singleton<Application>, public IXMLSerializable
	{
	public:
		
	SL_CONSTRUCTOR_ACCESS_LEVEL:
		Application(void);
		virtual~Application(void) override;

	public:
		bool Initialize(const std::string& resourceRootPath, const std::string& configDataPath,
			OPTIONAL HINSTANCE appInstanceHandler = nullptr);

		int Run(void);

		void SetRenderingFrame(float frame = DEFAULT_FRAME);

		void ShowCursor(bool isShow);

		bool IsRunning(void){ return _isRunning; }
		void Stop(void){ _isRunning = false; }


		inline void ShowCaptionMode(AppCaptionMode mode)
		{
			_data.SetCaptionMode(mode, true);
		}
		inline void UnshowCaptionMode(AppCaptionMode mode)
		{
			_data.SetCaptionMode(mode, false);
		}
		inline bool IsShowingCaptionMode(AppCaptionMode mode)
		{
			return _data.IsShowingCaptionMode(mode);
		}
		

//#########################################################################
#pragma region Serialize Function
		bool Serialize(const char* filePath);
		bool Serialize(XMLSerializer* serializer);
		bool Deserialize(const char* filePath);
		bool Deserialize(XMLSerializer* serializer);
#pragma endregion
//#########################################################################

	private:
		static LRESULT CALLBACK _WinProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
		void _UpdateWindowCaption(void);
		bool _CreateWindow(HINSTANCE appInstanceHandler);
	protected:
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