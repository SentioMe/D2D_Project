#pragma once

#ifndef __DXLIB_TEXTURE_CASHE_H__
#define __DXLIB_TEXTURE_CASHE_H__

/**
@namespace DXLib
@brief  Direct2Dのライブラリーをなすコンテンツ達の集まり
*/
namespace DXLib
{
	class TextureCashe sealed :
		public Singleton<TextureCashe>, public IXMLSerializable
	{
	SL_CONSTRUCTOR_ACCESS_LEVEL:
		TextureCashe(void)
			: _imagingFactory(nullptr)
		{
			_loadedTextureMap.clear();
		}
		~TextureCashe(void) override
		{
			this->Release();
		}

	public:
		void Release(void);

		const Texture* LoadTexture(const std::string& filePath);
		bool UnloadTexture(Texture* texture);

//#########################################################################
#pragma region Serialize Function
		bool Serialize(const char* filePath){ return true; }
		bool Serialize(XMLSerializer* serializer){ return true; }
		bool Deserialize(const char* filePath){ return true; }
		bool Deserialize(XMLSerializer* serializer){ return true; }
#pragma endregion
//#########################################################################
	
	private:
		bool _CreateImagingFactory(void);

	private:
		std::map<std::string, Texture*> _loadedTextureMap;
		PtrPropertyReadonly(IWICImagingFactory, _imagingFactory, Factory);


	};

}

#endif //!__DXLIB_TEXTURE_CASHE_H__