#pragma once

#ifndef __DXLIB_APPLICATION_DATA_H__
#define __DXLIB_APPLICATION_DATA_H__
/**
@namespace DXLib
@brief  Direct2Dのライブラリーをなすコンテンツ達の集まり
*/
namespace DXLib
{
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

	class ApplicationData : public IXMLSerializable
	{
	public:
		ApplicationData(void);
		~ApplicationData(void);

		inline void SetCaptionMode(AppCaptionMode mode, bool isShow)
		{
			if (isShow)
			{
				_appCaptionMode = (AppCaptionMode)(_appCaptionMode | mode);
			}
			else
			{
				_appCaptionMode
					= (AppCaptionMode)(_appCaptionMode - (_appCaptionMode & mode));
			}
		}
		inline bool IsShowingCaptionMode(AppCaptionMode mode)
		{
			return (_appCaptionMode & mode) == mode;
		}

#ifdef UNICODE
		inline std::wstring GetTitleName(void)
		{
			return (IsShowingCaptionMode(AppCaptionMode::TITLE))
				? ExtendString::StringToWString(_titleName)
				: ExtendString::WSTRING_EMPTY;
		}
		inline std::wstring GetIconPath(void)
		{
			return (IsShowingCaptionMode(AppCaptionMode::ICON))
				? ExtendString::StringToWString(_iconPath)
				: ExtendString::WSTRING_EMPTY;
		}
		inline std::wstring GetCaption(float frameRate = 0.0f)
		{
			static std::string caption;

			if (IsShowingCaptionMode(AppCaptionMode::TITLE))
				caption = ExtendString::Format("[%s]", _titleName.c_str());
			if (IsShowingCaptionMode(AppCaptionMode::FRAME))
				caption = ExtendString::Format("%s[Frame : %.1f]", caption.c_str(), frameRate);
			if (IsShowingCaptionMode(AppCaptionMode::CONFIGURATION))
				caption = ExtendString::Format("%s[Mode : %s]", caption.c_str(), CONFIGURATION_NAME);

			return ExtendString::StringToWString(caption);
		}
#else

		inline std::string GetTitleName(void)
		{
			return (IsShowingCaptionMode(AppCaptionMode::ICON))
				? _titleName
				: ExtendString::STRING_EMPTY;
		}
		inline std::string GetIconPath(void)
		{
			return (IsShowingCaptionMode(AppCaptionMode::ICON))
				? _iconPath
				: ExtendString::STRING_EMPTY;
		}
		inline std::string GetCaption(float frameRate = 0.0f)
		{
			static std::string caption;

			if (IsShowingCaptionMode(AppCaptionMode::TITLE))
				caption = ExtendString::Format("[%s]", _titleName.c_str());
			if (IsShowingCaptionMode(AppCaptionMode::FRAME))
				caption = ExtendString::Format("%s[Frame : %.1f]", caption.c_str(), frameRate);
			if (IsShowingCaptionMode(AppCaptionMode::CONFIGURATION))
				caption = ExtendString::Format("%s[Mode : %s]", caption.c_str(), CONFIGURATION_NAME);

			return caption;
		}
#endif
		inline bool IsEmptyIconPath(void)
		{
			return _iconPath.empty();
		}
	public:
		//#########################################################################
#pragma region Serialize Function
		bool Serialize(const char* filePath){ return true; }
		bool Serialize(XMLSerializer* serializer);
		bool Deserialize(const char* filePath){ return true; }
		bool Deserialize(XMLSerializer* serializer);
#pragma endregion
		//#########################################################################
	private:
		AppCaptionMode	_appCaptionMode;
		std::string		_titleName;
		std::string		_iconPath;

	public:
		Rect			appWindowRect;

		bool			useTitleBar;
		bool			useFullScreenMode;
	};
}

#endif //!__DXLIB_APPLICATION_DATA_H__