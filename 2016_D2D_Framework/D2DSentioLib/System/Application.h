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
		enum AppCaptionMode
		{
			TITLE = 1 << 0,
			FRAME = 1 << 1,
			CONFIGURATION = 1 << 2,
			ICON = 1 << 3,

			DEFAULT = TITLE | FRAME | CONFIGURATION,
			All = DEFAULT | ICON,

			NONE = 0
		};


	SL_CONSTRUCTOR_ACCESS_LEVEL:
		Application(void);
		virtual~Application(void) override;

	public:
		bool Initialize(const std::string& resourceRootPath, const std::string& configDataPath);

		int Run(void);

		void SetRenderingFrame(float frame = DEFAULT_FRAME);

		void ShowCursor(bool isShow);

		bool IsRunning(void){ return _isRunning; }
		void Stop(void){ _isRunning = false; }


		inline void ShowCaptionMode(AppCaptionMode mode)
		{
			_appCaptionMode = (AppCaptionMode)(_appCaptionMode | mode);
		}
		inline void UnshowCaptionMode(AppCaptionMode mode)
		{
			_appCaptionMode = (AppCaptionMode)(_appCaptionMode - (_appCaptionMode & mode));
		}
		inline bool IsShowingCaptionMode(AppCaptionMode mode)
		{
			return (_appCaptionMode & mode) == mode;
		}
		

//#########################################################################
#pragma region Serialize Function
		bool Serialize(const char* filePath){ return true; }
		bool Serialize(XMLSerializer* serializer){ return true; }
		bool Deserialize(const char* filePath){ return true; }
		bool Deserialize(XMLSerializer* serializer){ return true; }
#pragma endregion
//#########################################################################

	private:
		static LRESULT CALLBACK _WinProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
		void _UpdateWindowCaption(void);

	protected:
		virtual bool _OnInitialize(void){ return true; }

	protected:
		bool			_isRunning;
		AppCaptionMode	_appCaptionMode;
		LARGE_INTEGER	_renderingInterval;
		PropertyReadonly(std::string, _resourceRootPath, ResourceRootPath);
		PropertyReadonly(Rect, _clippingRect, ClippingRect);
		PropertyReadonly(HINSTANCE, _hInstance, HInstance);
		PropertyReadonly(HWND, _hWnd, HWnd);
	};

}

#endif //!__DXLIB_APPLICATION_H__