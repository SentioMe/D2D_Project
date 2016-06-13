#pragma once

#ifndef __DXLIB_TEXTURE_H__
#define __DXLIB_TEXTURE_H__


#pragma comment(lib, "WindowsCodecs.lib")
#include <wincodec.h>
/**
@namespace DXLib
@brief  Direct2Dのライブラリーをなすコンテンツ達の集まり
*/
namespace DXLib
{
	class Texture sealed
	{
		friend class Sprite;
	public:
		Texture(void);
		~Texture(void);

		bool Initialize(const std::string& filePath, IWICImagingFactory* imagingFactory);
	private:
		ID2D1Bitmap*					_d2dBitmap;
		D2D1_BITMAP_INTERPOLATION_MODE	_drawingQuality;
		byte							_columnCount;
		byte							_rowCount;
		Size							_cellSize;
		Size							_size;
	};

}
#endif //!__DXLIB_TEXTURE_H__