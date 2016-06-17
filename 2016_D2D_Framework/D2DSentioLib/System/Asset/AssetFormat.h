#pragma once


#ifndef __SENTIO_D2DLIB_ASSET_FORMAT_H__
#define __SENTIO_D2DLIB_ASSET_FORMAT_H__

/**
@namespace SentioD2DLib
@brief  Direct2Dのライブラリーをなすコンテンツ達の集まり
*/
namespace SentioD2DLib
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

#endif //!__SENTIO_D2DLIB_ASSET_FORMAT_H__