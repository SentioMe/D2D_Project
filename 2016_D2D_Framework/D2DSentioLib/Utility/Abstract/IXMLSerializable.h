#pragma once

#ifndef __SENTIO_D2DLIB_IXMLSERIALIZABLE_H__
#define __SENTIO_D2DLIB_IXMLSERIALIZABLE_H__
/**
@namespace SentioD2DLib
@brief  Direct2Dのライブラリーをなすコンテンツ達の集まり
*/
namespace SentioD2DLib
{
	class XMLSerializer;

	/**
	@interface IXMLSerializable
	@brief XML Serializeを使う時に呼び出せる関数の形を定義したインタフェース
	*/
	__interface IXMLSerializable
	{
		/** 伝達されたパスからXMLSerializerを作ってSerializeをします。*/
		bool Serialize(const char* filePath);
		/** 伝達されたXMLSerializerを使ってSerializeをします。*/
		bool Serialize(XMLSerializer* serializer);
		/** 伝達されたパスからXMLSerializerを作ってDeserializeをします。*/
		bool Deserialize(const char* filePath);
		/** 伝達されたXMLSerializerを使ってDeserializeをします。*/
		bool Deserialize(XMLSerializer* serializer);
	};
}
#endif //!__SENTIO_D2DLIB_IXMLSERIALIZABLE_H__