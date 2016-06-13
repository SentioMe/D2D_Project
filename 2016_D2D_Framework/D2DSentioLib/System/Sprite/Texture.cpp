#include "SentioD2D.h"
#include "Texture.h"

namespace DXLib
{
	Texture::Texture(void)
		: _d2dBitmap(nullptr), _drawingQuality(D2D1_BITMAP_INTERPOLATION_MODE_LINEAR),
		_rowCount(0), _columnCount(0)
	{
	}

	Texture::~Texture(void)
	{
		SAFE_RELEASE(_d2dBitmap);
	}

	bool Texture::Initialize(const std::string& filePath, IWICImagingFactory* imagingFactory)
	{
		HRESULT ret = E_FAIL;

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

		////이미지 정보 구조체 할당
		//m_ImageInfo = new ImageInfo();
		////D2D형식의 Bitmap을 생성한다
		//lHrMsg = D2D_Device->CreateBitmapFromWicBitmap(ipConvertor, nullptr, &m_ImageInfo->ipD2DBitmap);
		//if (SUCCEEDED(lHrMsg))
		//	m_ImageInfo->SetInfo(stImageInfo);

		releaseRamda();
		return true;

	}
}