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
		bool Serialize(const char* filePath) override { return true; }
		bool Serialize(XMLSerializer* serializer) override { return true; }
		bool Deserialize(const char* filePath) override { return true; }
		bool Deserialize(XMLSerializer* serializer) override { return true; }
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
		bool Serialize(const char* filePath) override;
		bool Serialize(XMLSerializer* serializer) override;
		bool Deserialize(const char* filePath) override;
		bool Deserialize(XMLSerializer* serializer) override;
#pragma endregion
//#########################################################################

	private:
		//PropertyReadonly(ApplicationData, _appData, AppData);
		PropertyReadonly(LocalData, _localData, LocalData);
	};
}

#endif //!__DXLIB_MASTER_DATA_H__