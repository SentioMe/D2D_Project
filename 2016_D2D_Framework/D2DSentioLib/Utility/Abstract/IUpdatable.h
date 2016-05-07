#pragma once

/**
@namespace DXLib
@brief  Direct2Dのライブラリーをなすコンテンツ達の集まり
*/
namespace DXLib
{
	class IUpdatable
	{
	public:
		virtual void Update(float deltaTime) = 0;
	};
}