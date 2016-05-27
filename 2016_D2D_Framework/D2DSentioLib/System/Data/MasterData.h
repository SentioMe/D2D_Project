#pragma once

#ifndef __DXLIB_MASTER_DATA_H__
#define __DXLIB_MASTER_DATA_H__
/**
@namespace DXLib
@brief  Direct2Dのライブラリーをなすコンテンツ達の集まり
*/
namespace DXLib
{
	
	class LocalData : public IXMLSerializable
	{
	public:
		LocalData(void){}
		~LocalData(void){}

	public:
//#########################################################################
#pragma region Serialize Function
		bool Serialize(const char* filePath){ return true; }
		bool Serialize(XMLSerializer* serializer)
		{ 
			return true;
		}
		bool Deserialize(const char* filePath){ return true; }
		bool Deserialize(XMLSerializer* serializer)
		{
			return true;
		}
#pragma endregion
//#########################################################################
	public:
	};





	class MasterData : public IXMLSerializable
	{
	public:
		MasterData(void){}
		~MasterData(void){}

//#########################################################################
#pragma region Serialize Function
		bool Serialize(const char* filePath);
		bool Serialize(XMLSerializer* serializer);
		bool Deserialize(const char* filePath);
		bool Deserialize(XMLSerializer* serializer);
#pragma endregion
//#########################################################################

	private:
		//PropertyReadonly(ApplicationData, _appData, AppData);
		PropertyReadonly(LocalData, _localData, LocalData);
	};
}

#endif //!__DXLIB_MASTER_DATA_H__