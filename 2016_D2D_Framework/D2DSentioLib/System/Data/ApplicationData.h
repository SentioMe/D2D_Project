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

		inline const char* GetTitleName(void)
		{
			return (IsShowingCaptionMode(AppCaptionMode::ICON))
				? _titleName.c_str()
				: ExtendString::EMPTY.c_str();
		}
		inline const char* GetIconPath(void)
		{
			return (IsShowingCaptionMode(AppCaptionMode::ICON))
				? _iconPath.c_str()
				: ExtendString::EMPTY.c_str();
		}
		inline const char* GetCaption(float frameRate = 0.0f, float elapsedTime = 0.0f)
		{
			if (IsShowingCaptionMode(AppCaptionMode::TITLE))
				_caption = ExtendString::Format("[%s]", _titleName.c_str());
			if (IsShowingCaptionMode(AppCaptionMode::FRAME))
				_caption = ExtendString::Format("%s[Frame : %.1f, ElapsedTime : %.4f]", _caption.c_str(), frameRate, elapsedTime);
			if (IsShowingCaptionMode(AppCaptionMode::CONFIGURATION))
				_caption = ExtendString::Format("%s[Mode : %s]", _caption.c_str(), CONFIGURATION_NAME);

			return _caption.c_str();
		}

		inline bool IsEmptyIconPath(void)
		{
			return _iconPath.empty();
		}

//#########################################################################
#pragma region Serialize Function
		bool Serialize(const char* filePath) override { return true; }
		bool Serialize(XMLSerializer* serializer) override;
		bool Deserialize(const char* filePath) override { return true; }
		bool Deserialize(XMLSerializer* serializer) override;
#pragma endregion
//#########################################################################
	private:
		AppCaptionMode	_appCaptionMode;
		std::string		_titleName;
		std::string		_iconPath;

		std::string		_caption;

	public:
		Rect			appWindowRect;

		bool			useTitleBar;
		bool			useFullScreenMode;
	};
}

#endif //!__DXLIB_APPLICATION_DATA_H__