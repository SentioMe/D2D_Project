#pragma once

#ifndef __SENTIO_D2DLIB_ICONVERTIBLE_H__
#define __SENTIO_D2DLIB_ICONVERTIBLE_H__

#include <string>
/**
@namespace SentioD2DLib
@brief  Direct2Dのライブラリーをなすコンテンツ達の集まり
*/
namespace SentioD2DLib
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
#endif //!__SENTIO_D2DLIB_ICONVERTIBLE_H__