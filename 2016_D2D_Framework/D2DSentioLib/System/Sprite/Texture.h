#pragma once

#ifndef __SENTIO_D2DLIB_TEXTURE_H__
#define __SENTIO_D2DLIB_TEXTURE_H__


#pragma comment(lib, "WindowsCodecs.lib")
#include <wincodec.h>
/**
@namespace SentioD2DLib
@brief  Direct2Dのライブラリーをなすコンテンツ達の集まり
*/
namespace SentioD2DLib
{
	class Texture sealed : public AssetBase
	{
		friend class Sprite;
	SL_CONSTRUCTOR_ACCESS_LEVEL:
		Texture(void);
		~Texture(void);

	public:
		/** cocos2Dの方法で、割り当てます。*/
		static Texture* Create(const std::string& filePath, IWICImagingFactory* imagingFactory);

		bool Initialize(const std::string& filePath, IWICImagingFactory* imagingFactory);

		void Reset(void) override;
		
	protected:
		const AssetFormat* _CreateFormat(const std::string& assetPath) override;

	public:
//#########################################################################
#pragma region Serialize Function
		bool Serialize(XMLSerializer* serializer) override;
		bool Deserialize(XMLSerializer* serializer) override;
#pragma endregion
//#########################################################################=

	

	private:
		ID2D1Bitmap*					_d2dBitmap;
		D2D1_BITMAP_INTERPOLATION_MODE	_drawingQuality;
		byte							_columnCount;
		byte							_rowCount;
		Size							_cellSize;
		Size							_size;
	};

}
#endif //!__SENTIO_D2DLIB_TEXTURE_H__