#pragma once

#ifndef __DXLIB_SOUND_ASSET_FORMAT_H__
#define __DXLIB_SOUND_ASSET_FORMAT_H__
/**
@namespace DXLib
@brief  Direct2Dのライブラリーをなすコンテンツ達の集まり
*/
namespace DXLib
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

#endif //!__DXLIB_SOUND_ASSET_FORMAT_H__