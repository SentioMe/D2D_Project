#pragma once

#ifndef __DXLIB_TEXTURE_CASHE_H__
#define __DXLIB_TEXTURE_CASHE_H__

/**
@namespace DXLib
@brief  Direct2Dのライブラリーをなすコンテンツ達の集まり
*/
namespace DXLib
{
	class TextureCashe sealed :
		public Singleton<TextureCashe>, public IXMLSerializable
	{
	SL_CONSTRUCTOR_ACCESS_LEVEL:
		TextureCashe(void)
		{
		}
		~TextureCashe(void) override
		{
		}

	public:

//#########################################################################
#pragma region Serialize Function
		bool Serialize(const char* filePath){ return true; }
		bool Serialize(XMLSerializer* serializer){ return true; }
		bool Deserialize(const char* filePath){ return true; }
		bool Deserialize(XMLSerializer* serializer){ return true; }
#pragma endregion
//#########################################################################
	};

}

#endif //!__DXLIB_TEXTURE_CASHE_H__