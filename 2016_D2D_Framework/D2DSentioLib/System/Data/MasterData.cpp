#include "SentioD2D.h"
#include "MasterData.h"

namespace DXLib
{

//#########################################################################
#pragma region Serialize Function
	bool ApplicationData::Serialize(const char* filePath)
	{ 
		return true; 
	}
	bool ApplicationData::Serialize(XMLSerializer* serializer)
	{ 
		return true; 
	}
	bool ApplicationData::Deserialize(const char* filePath)
	{ 
		return true; 
	}
	bool ApplicationData::Deserialize(XMLSerializer* serializer)
	{
		return true;
	}
#pragma endregion
//#########################################################################












	

//#########################################################################
#pragma region Serialize Function
	bool MasterData::Serialize(const char* filePath)
	{
		return true;
	}
	bool MasterData::Serialize(XMLSerializer* serializer)
	{
		return true;
	}
	bool MasterData::Deserialize(const char* filePath)
	{
		return true;
	}
	bool MasterData::Deserialize(XMLSerializer* serializer)
	{
		serializer->Read("AppData", _appData);
		serializer->Read("LocalData", _localData);

		return true;
	}
#pragma endregion
//#########################################################################
}