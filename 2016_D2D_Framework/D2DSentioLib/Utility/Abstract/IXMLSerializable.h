#pragma once

/**
@namespace DXLib
@brief  Direct2Dのライブラリーをなすコンテンツ達の集まり
*/
namespace DXLib
{
	class XMLSerializer;
	class IXMLSerializable
	{
	public:
		virtual bool Serialize(const char* filePath) { return true; }
		virtual bool Serialize(XMLSerializer* serializer)  { return true; }
		virtual bool Deserialize(const char* filePath) { return true; }
		virtual bool Deserialize(XMLSerializer* serializer)  { return true; }
	};
}