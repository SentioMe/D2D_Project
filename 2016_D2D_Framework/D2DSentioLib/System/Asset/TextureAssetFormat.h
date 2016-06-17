#pragma once

#ifndef __SENTIO_D2DLIB_TEXTURE_ASSET_FORMAT_H__
#define __SENTIO_D2DLIB_TEXTURE_ASSET_FORMAT_H__
/**
@namespace SentioD2DLib
@brief  Direct2Dのライブラリーをなすコンテンツ達の集まり
*/
namespace SentioD2DLib
{
	class TextureAssetFormat : public AssetFormat
	{
	SL_CONSTRUCTOR_ACCESS_LEVEL:
		TextureAssetFormat(const std::string& filePath)
			: AssetFormat(filePath)
		{
			_assetType = ASSET_TYPE::TEXTURE;
		}
		virtual ~TextureAssetFormat(void) override
		{
		}
	public:
	};

}

#endif //!__SENTIO_D2DLIB_TEXTURE_ASSET_FORMAT_H__