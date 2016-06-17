#include "SentioD2D.h"
#include "Texture.h"

namespace SentioD2DLib
{
	Texture::Texture(void)
		: _d2dBitmap(nullptr)
	{
		Reset();
	}

	Texture::~Texture(void)
	{
		SAFE_RELEASE(_d2dBitmap);
	}

	Texture* Texture::Create(const std::string& filePath, IWICImagingFactory* imagingFactory)
	{
		ALLOCATE(Texture, newTexture);

		if (nullptr == newTexture 
			|| false == newTexture->Initialize(filePath, imagingFactory))
		{
			SAFE_DELETE(newTexture);
		}

		return newTexture;
	}

	bool Texture::Initialize(const std::string& filePath, IWICImagingFactory* imagingFactory)
	{
		IWICBitmapDecoder* bitmapDecoder = nullptr;
		IWICBitmapFrameDecode* frameDecode = nullptr;
		IWICFormatConverter* convertor = nullptr;

		auto releaseRamda = [&bitmapDecoder, &frameDecode, &convertor]() ->void{
			SAFE_RELEASE(convertor);
			SAFE_RELEASE(frameDecode);
			SAFE_RELEASE(bitmapDecoder); };

		//Create a decoder
		if (FAILED(imagingFactory->CreateDecoderFromFilename(
			ExtendString::ToWString(filePath).c_str(),			//File path
			nullptr,											//GUID (Default : 0)
			GENERIC_READ,										//Access
			WICDecodeMetadataCacheOnDemand,						//Image cashe information (multi layer is requirement to exception)
			&bitmapDecoder)))
		{
			releaseRamda();
			return false;
		}

		//Get image frame information
		if (FAILED(bitmapDecoder->GetFrame(0, &frameDecode)))
		{
			releaseRamda();
			return false;
		}

		//Create and Initialize a converter
		if (FAILED(imagingFactory->CreateFormatConverter(&convertor))
			|| FAILED(convertor->Initialize(
			frameDecode,					//Image frame inforamtion
			GUID_WICPixelFormat32bppPBGRA,	//32bit RGBA PixelFormat
			WICBitmapDitherTypeNone,		//None using option : Outline
			nullptr,						//None using option : WIC Palette
			0.0f,							//None using option : Aplpha rendering effect
			WICBitmapPaletteTypeCustom		//Checked option : Bitmap Palette (Defulat : Custom)
			)))
		{
			releaseRamda();
			return false;
		}
		
		//Create a bitmap & Check Meta Data
		if (SUCCEEDED((D2DRenderTarget->CreateBitmapFromWicBitmap(convertor, nullptr, &this->_d2dBitmap))))
		{
			_CreateFormat(filePath);
			_SetFromMetaData(filePath);
		}	

		releaseRamda();
		return true;

	}

	void Texture::Reset(void)
	{
		_size = (_d2dBitmap != nullptr) ? _d2dBitmap->GetSize() : Size::One;
		_columnCount = 1;
		_rowCount = 1;
		_drawingQuality = D2D1_BITMAP_INTERPOLATION_MODE::D2D1_BITMAP_INTERPOLATION_MODE_LINEAR;
		_cellSize = _size;
	}

//#########################################################################
#pragma region Serialize Function
	bool Texture::Serialize(XMLSerializer* serializer)
	{
		assert(_d2dBitmap != nullptr, "Bitmap resource should not null");

		serializer->Write("Size", _size);
		serializer->Write("Column", _columnCount);
		serializer->Write("Row", _rowCount);
		serializer->Write("DrawingQuality", _drawingQuality);

		return true;
	}
	bool Texture::Deserialize(XMLSerializer* serializer)
	{
		serializer->Read("Size", _size);

		unsigned int column;
		serializer->Read("Column", column, 1);
		_columnCount = ExtendMath::Clamp(column, 1, 255);

		unsigned int row;
		serializer->Read("Row", row, 1);
		_rowCount = ExtendMath::Clamp(row, 1, 255);

		_cellSize = Size(_size.width / column, _size.height / row);

		int quality;
		serializer->Read("DrawingQuality", quality, D2D1_BITMAP_INTERPOLATION_MODE::D2D1_BITMAP_INTERPOLATION_MODE_LINEAR);
		_drawingQuality = (D2D1_BITMAP_INTERPOLATION_MODE)quality;

		return true;
	}
#pragma endregion
//#########################################################################

	const AssetFormat* Texture::_CreateFormat(const std::string& assetPath)
	{
		if (_format == nullptr)
			_format = new TextureAssetFormat(assetPath);

		return _format;
	}
}