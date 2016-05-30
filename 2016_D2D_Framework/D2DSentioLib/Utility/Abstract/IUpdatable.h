#pragma once

#ifndef __DXLIB_IUPDATABLE_H__
#define __DXLIB_IUPDATABLE_H__
/**
@namespace DXLib
@brief  Direct2Dのライブラリーをなすコンテンツ達の集まり
*/
namespace DXLib
{
	/**
	@interface IUpdatable
	@brief 毎フレームのたび、呼び出せる更新の関数の形を定義したインタフェース
	*/
	__interface IUpdatable
	{
		void Update(float deltaTime);
	};
}
#endif //!__DXLIB_IUPDATABLE_H__