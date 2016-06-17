#pragma once

#ifndef __SENTIO_D2DLIB_IUPDATABLE_H__
#define __SENTIO_D2DLIB_IUPDATABLE_H__
/**
@namespace SentioD2DLib
@brief  Direct2Dのライブラリーをなすコンテンツ達の集まり
*/
namespace SentioD2DLib
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
#endif //!__SENTIO_D2DLIB_IUPDATABLE_H__