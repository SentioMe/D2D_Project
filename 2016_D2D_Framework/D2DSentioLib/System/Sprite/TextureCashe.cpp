#include "SentioD2D.h"
#include "TextureCashe.h"

namespace DXLib
{
	void TextureCashe::Release(void)
	{
		ExtendCollection::Destroy(_loadedTextureMap);

		ULONG message = _imagingFactory->Release();
		assert(message == 0 && "There are objects that have not been deallocated in the objects allocated in the WIC factory");
		_imagingFactory = nullptr;
	}

	const Texture* TextureCashe::LoadTexture(const std::string& filePath)
	{
		return nullptr;
	}
	bool TextureCashe::UnloadTexture(Texture* texture)
	{
		return false;	
	}

	bool TextureCashe::_CreateImagingFactory(void)
	{
		::CoInitialize(nullptr);

		if (FAILED(::CoCreateInstance(
			CLSID_WICImagingFactory,
			NULL, 
			CLSCTX_INPROC_SERVER, 
			IID_PPV_ARGS(&_imagingFactory))))
		{
			SAFE_RELEASE(_imagingFactory);

			return false;
		}

		return true;
	}
}