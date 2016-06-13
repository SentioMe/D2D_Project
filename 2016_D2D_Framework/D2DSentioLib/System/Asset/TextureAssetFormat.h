#pragma once

#ifndef __DXLIB_TEXTURE_ASSET_FORMAT_H__
#define __DXLIB_TEXTURE_ASSET_FORMAT_H__
/**
@namespace DXLib
@brief  Direct2Dのライブラリーをなすコンテンツ達の集まり
*/
namespace DXLib
{
	class TextureAssetFormat : public AssetFormat
	{
	SL_CONSTRUCTOR_ACCESS_LEVEL:
		TextureAssetFormat(const std::string& filePath, int aa)
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

#endif //!__DXLIB_TEXTURE_ASSET_FORMAT_H__