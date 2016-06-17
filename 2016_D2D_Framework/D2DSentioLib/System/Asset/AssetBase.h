#pragma once


#ifndef __SENTIO_D2DLIB_ASSET_BASE_H__
#define __SENTIO_D2DLIB_ASSET_BASE_H__

/**
@namespace SentioD2DLib
@brief  Direct2Dのライブラリーをなすコンテンツ達の集まり
*/
namespace SentioD2DLib
{
	class AssetFormat;

	class AssetBase : public IXMLSerializable
	{
	public:
		static const std::string META_FILE_EXTENSION;

	public:
		AssetBase(void);
		virtual~AssetBase(void);

		virtual void Reset(void) = 0;

//#########################################################################
#pragma region Serialize Function
		virtual bool Serialize(const char* filePath) override;
		virtual bool Serialize(XMLSerializer* serializer) override
		{ 
			return true; 
		}
		virtual bool Deserialize(const char* filePath) override;
		virtual bool Deserialize(XMLSerializer* serializer) override
		{
			return true;
		}
#pragma endregion
//#########################################################################

	protected:
		virtual const AssetFormat* _CreateFormat(const std::string& assetPath) = 0;
		bool _SetFromMetaData(const std::string& assetPath);
		
	protected:
		PtrPropertyReadonly(AssetFormat, _format, Format);
	};

}

#endif __SENTIO_D2DLIB_ASSET_BASE_H__