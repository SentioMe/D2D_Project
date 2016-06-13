#pragma once

#ifndef __DXLIB_ICONVERTIBLE_H__
#define __DXLIB_ICONVERTIBLE_H__

#include <string>
/**
@namespace DXLib
@brief  Direct2Dのライブラリーをなすコンテンツ達の集まり
*/
namespace DXLib
{

	/**
	@interface IConvertible
	@brief 指定したタイプでインスタンスを変換する関数の形を定義したインタフェース
	*/
	__interface IConvertible
	{
		/** C#の方法で、記述を定義します。*/
		std::string ToString(void) const;
	};
}
#endif //!__DXLIB_ICONVERTIBLE_H__