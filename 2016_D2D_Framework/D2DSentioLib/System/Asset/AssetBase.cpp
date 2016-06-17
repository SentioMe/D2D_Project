#include "SentioD2D.h"
#include "AssetBase.h"

namespace SentioD2DLib
{
	const std::string AssetBase::META_FILE_EXTENSION = ".sdmeta";

	AssetBase::AssetBase(void)
		: _format(nullptr)
	{

	}
	AssetBase::~AssetBase(void)
	{
		SAFE_DELETE(_format);
	}

	//#########################################################################
#pragma region Serialize Function
	bool AssetBase::Serialize(const char* filePath)
	{
		XMLSerializer* serializer = new XMLSerializer(filePath);

		if (false == Serialize(serializer))
			return serializer->Close();

		serializer->Save();

		return serializer->Close();
	}
	bool AssetBase::Deserialize(const char* filePath)
	{
		XMLSerializer* serializer = XMLSerializer::Load(filePath);
		if (serializer == nullptr)
			return false;

		this->Deserialize(serializer);

		return serializer->Close();
	}
#pragma endregion
	//#########################################################################

	bool AssetBase::_SetFromMetaData(const std::string& assetPath)
	{
		assert(assetPath.empty() == false, "Passed path string is empty");

		std::string metaPath = Path::ReplaceExtension(assetPath, META_FILE_EXTENSION);

		if (false == Deserialize(metaPath.c_str()))
		{
			this->Reset();
			return Serialize(metaPath.c_str());
		}

		return true;
	}
}
