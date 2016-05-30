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
	class IConvertible
	{
	public:
		/** C#の方法で、記述を定義します。*/
		virtual std::string		ToString(void)	const = 0;


		/** ToString(void)を呼べる事でノードを文字列で変換します。*/
		operator const char*(void)
		{
			return ToString().c_str();
		}
	};
}
#endif //!__DXLIB_ICONVERTIBLE_H__