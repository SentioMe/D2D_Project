#pragma once

#ifndef __SENTIO_D2DLIB_LABEL_H__
#define __SENTIO_D2DLIB_LABEL_H__
/**
@namespace SentioD2DLib
@brief  Direct2Dのライブラリーをなすコンテンツ達の集まり
*/
namespace SentioD2DLib
{
	class Label : public BagicNode
	{
	SL_CONSTRUCTOR_ACCESS_LEVEL:
		Label(void)
		{

		}
		virtual ~Label(void) override
		{

		}
	};

}
#endif //!__SENTIO_D2DLIB_LABEL_H__