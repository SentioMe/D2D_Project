#pragma once

#ifndef __SENTIO_D2DLIB_TEXTURE_CASHE_H__
#define __SENTIO_D2DLIB_TEXTURE_CASHE_H__

/**
@namespace SentioD2DLib
@brief  Direct2Dのライブラリーをなすコンテンツ達の集まり
*/
namespace SentioD2DLib
{
	class TextureCashe sealed : public Singleton<TextureCashe>
	{
	SL_CONSTRUCTOR_ACCESS_LEVEL:
		TextureCashe(void);
		~TextureCashe(void) override;
		
	public:

		const Texture* LoadTexture(const std::string& filePath);
		bool UnloadTexture(Texture* texture);
		bool UnloadTexture(const std::string& filePath);
	private:
		bool _CreateImagingFactory(void);

	private:
		std::map<std::string, Texture*> _loadedTextureMap;
		PtrPropertyReadonly(IWICImagingFactory, _imagingFactory, Factory);


	};

}

#endif //!__SENTIO_D2DLIB_TEXTURE_CASHE_H__