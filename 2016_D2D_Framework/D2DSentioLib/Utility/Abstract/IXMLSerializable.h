#pragma once

/**
@namespace DXLib
@brief  Direct2Dのライブラリーをなすコンテンツ達の集まり
*/
namespace DXLib
{
	__interface IXMLSerializable
	{
		bool Serialize(const char* path);
		IXMLSerializable* Deserialize(const char path);
	};
}