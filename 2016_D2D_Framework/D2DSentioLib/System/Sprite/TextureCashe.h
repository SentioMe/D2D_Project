#pragma once

/**
@namespace DXLib
@brief  Direct2Dのライブラリーをなすコンテンツ達の集まり
*/
namespace DXLib
{
	class TextureCashe sealed : public Singleton<TextureCashe>
	{
	SL_CONSTRUCTOR_ACCESS_LEVEL:
		TextureCashe(void)
		{
		}
		~TextureCashe(void) override
		{
		}
	};

}