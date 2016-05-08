#pragma once

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