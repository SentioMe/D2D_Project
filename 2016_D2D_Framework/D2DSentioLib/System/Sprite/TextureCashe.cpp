#include "SentioD2D.h"
#include "TextureCashe.h"

namespace SentioD2DLib
{
	TextureCashe::TextureCashe(void)
	{
		bool result = _CreateImagingFactory();
#if DEBUG
		assert(result != false, "Failed create WIC imaging factory");
#else
		if (result == false)
		{
			this->Destroy();
			return;
		}
#endif
		_loadedTextureMap.clear();

		LOG("Create a instacne of TextureCashe");
	}
	TextureCashe::~TextureCashe(void)
	{
		ExtendCollection::Destroy(_loadedTextureMap);

		ULONG message = _imagingFactory->Release();
		assert(message == 0 && "There are objects that have not been deallocated in the objects allocated in the WIC factory");
		_imagingFactory = nullptr;

		LOG("Destroy a instacne of TextureCashe");
	}

	const Texture* TextureCashe::LoadTexture(const std::string& filePath)
	{
		assert(filePath.empty(), "Passed filePath is empty");

		Texture* texture = nullptr;
		if (false == ExtendCollection::TryGetValue(_loadedTextureMap, filePath, texture))
		{
			texture = Texture::Create(filePath, _imagingFactory);
			if (texture == nullptr)
			{
				LOG_WARNING(ExtendString::Format("Failed to create a texture : ", filePath.c_str()).c_str());
				return nullptr;
			}

			_loadedTextureMap.insert(std::pair<std::string, Texture*>(filePath, texture));
		}

		return texture;
	}
	bool TextureCashe::UnloadTexture(Texture* texture)
	{
		assert(texture != nullptr, "Passed texture is null");

		return UnloadTexture(texture->GetFormat()->GetFilePath());
	}
	bool TextureCashe::UnloadTexture(const std::string& filePath)
	{
		assert(filePath.empty(), "Passed filePath is empty");

		if (true == ExtendCollection::IsContains(_loadedTextureMap, filePath))
		{
			_loadedTextureMap.erase(filePath);
			return true;
		}

		LOG_WARNING(ExtendString::Format("Is not found a texture : ", filePath.c_str()).c_str());
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