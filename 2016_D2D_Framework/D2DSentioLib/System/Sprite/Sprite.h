#pragma once


#ifndef __DXLIB_SPRITE_H__
#define __DXLIB_SPRITE_H__
/**
@namespace DXLib
@brief  Direct2Dのライブラリーをなすコンテンツ達の集まり
*/
namespace DXLib
{
	class Sprite : public BagicNode
	{
	SL_CONSTRUCTOR_ACCESS_LEVEL:
		Sprite(void)
		{

		}
		virtual ~Sprite(void) override
		{

		}
	};

}
#endif //!__DXLIB_SPRITE_H__