#include "SentioD2D.h"
#include "AssetFormat.h"

namespace DXLib
{
	AssetFormat::AssetFormat(const std::string& filePath)
		: _assetType(ASSET_TYPE::NONE), _filePath(filePath)
	{
	}
	AssetFormat::~AssetFormat(void)
	{
	}

}