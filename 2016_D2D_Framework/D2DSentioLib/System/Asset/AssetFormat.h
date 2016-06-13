#pragma once


#ifndef __DXLIB_ASSET_FORMAT_H__
#define __DXLIB_ASSET_FORMAT_H__
/**
@namespace DXLib
@brief  Direct2Dのライブラリーをなすコンテンツ達の集まり
*/
namespace DXLib
{
	class AssetFormat : public IConvertible
	{
	public:
		enum ASSET_TYPE
		{
			TEXTURE,
			SOUND,
			NONE
		};

	SL_CONSTRUCTOR_ACCESS_LEVEL:
		AssetFormat(const std::string& filePath);
		virtual~AssetFormat(void);

	private:
		PropertyReadonly(ASSET_TYPE, _assetType, AssetType);
		PropertyReadonly(std::string, _filePath, FilePath);

	public:
		inline std::string Name(void) const
		{
			return Path::FileNameWithoutExtension(_filePath);
		}

		//#########################################################################
#pragma region Convert Funtion
		inline std::string ToString(void) const override
		{
			return Name();
		}
#pragma endregion
		//#########################################################################
	};
}

#endif //!__DXLIB_ASSET_FORMAT_H__