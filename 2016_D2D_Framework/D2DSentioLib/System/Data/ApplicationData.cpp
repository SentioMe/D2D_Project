#include "SentioD2D.h"
#include "ApplicationData.h"


namespace DXLib
{
	ApplicationData::ApplicationData(void)
		: _appCaptionMode(AppCaptionMode::NONE), useTitleBar(false), useFullScreenMode(false),
		_titleName(ExtendString::EMPTY), _iconPath(ExtendString::EMPTY), _caption(ExtendString::EMPTY)
	{
	}

	ApplicationData::~ApplicationData(void)
	{

	}


	//#########################################################################
#pragma region Serialize Function
	bool ApplicationData::Serialize(XMLSerializer* serializer)
	{
		serializer->Write("CaptionMode:UseTitleName", IsShowingCaptionMode(AppCaptionMode::TITLE));
		serializer->Write("CaptionMode:UseFrameInfo", IsShowingCaptionMode(AppCaptionMode::FRAME));
		serializer->Write("CaptionMode:UseConfiguration", IsShowingCaptionMode(AppCaptionMode::CONFIGURATION));
		serializer->Write("CaptionMode:UseIcon", IsShowingCaptionMode(AppCaptionMode::ICON));

		serializer->Write("UseFullScreenMode", useFullScreenMode);
		serializer->Write("TitleName", _titleName.c_str());
		serializer->Write("IconPath", _iconPath.c_str());
		serializer->Write("Window_Resolution", appWindowRect);

		return true;
	}

	bool ApplicationData::Deserialize(XMLSerializer* serializer)
	{
		bool useTitleName;
		serializer->Read("CaptionMode:UseTitleName", useTitleName, false);
		bool useFrameInfo;
		serializer->Read("CaptionMode:UseFrameInfo", useFrameInfo, false);
		bool useConfiguration;
		serializer->Read("CaptionMode:UseConfiguration", useConfiguration, false);
		bool useIcon;
		serializer->Read("CaptionMode:UseIcon", useIcon, false);

		SetCaptionMode(AppCaptionMode::TITLE, useTitleName);
		SetCaptionMode(AppCaptionMode::FRAME, useFrameInfo);
		SetCaptionMode(AppCaptionMode::CONFIGURATION, useConfiguration);
		SetCaptionMode(AppCaptionMode::ICON, useIcon);


		serializer->Read("UseFullScreenMode", useFullScreenMode, false);
		char* titleName;
		serializer->Read("TitleName", titleName, "MyApp");
		_titleName = titleName;
		char* iconPath;
		serializer->Read("IconPath", iconPath);
		_iconPath = iconPath;
		serializer->Read("Window_Resolution", appWindowRect);

		return true;
	}

#pragma endregion
	//#########################################################################
}