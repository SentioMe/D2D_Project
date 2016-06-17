#pragma once


#ifndef __SENTIO_D2DLIB_SPRITE_H__
#define __SENTIO_D2DLIB_SPRITE_H__
/**
@namespace SentioD2DLib
@brief  Direct2Dのライブラリーをなすコンテンツ達の集まり
*/
namespace SentioD2DLib
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
#endif //!__SENTIO_D2DLIB_SPRITE_H__