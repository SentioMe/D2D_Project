#pragma once

#ifndef __DXLIB_LABEL_H__
#define __DXLIB_LABEL_H__
/**
@namespace DXLib
@brief  Direct2Dのライブラリーをなすコンテンツ達の集まり
*/
namespace DXLib
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
#endif //!__DXLIB_LABEL_H__