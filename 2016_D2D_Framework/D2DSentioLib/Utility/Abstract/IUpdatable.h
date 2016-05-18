#pragma once

#ifndef __DXLIB_IUPDATABLE_H__
#define __DXLIB_IUPDATABLE_H__
/**
@namespace DXLib
@brief  Direct2Dのライブラリーをなすコンテンツ達の集まり
*/
namespace DXLib
{
	
	__interface IUpdatable
	{
		void Update(float deltaTime);
	};
}
#endif //!__DXLIB_IUPDATABLE_H__