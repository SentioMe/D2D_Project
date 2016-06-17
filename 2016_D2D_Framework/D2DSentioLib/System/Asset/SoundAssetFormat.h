#pragma once

#ifndef __SENTIO_D2DLIB_SOUND_ASSET_FORMAT_H__
#define __SENTIO_D2DLIB_SOUND_ASSET_FORMAT_H__
/**
@namespace SentioD2DLib
@brief  Direct2Dのライブラリーをなすコンテンツ達の集まり
*/
namespace SentioD2DLib
{
	class SoundAssetFormat : public AssetFormat
	{
	SL_CONSTRUCTOR_ACCESS_LEVEL:
		SoundAssetFormat(const std::string& filePath)
			: AssetFormat(filePath)
		{
		}
		virtual ~SoundAssetFormat(void) override
		{
		}
	};
}

#endif //!__SENTIO_D2DLIB_SOUND_ASSET_FORMAT_H__