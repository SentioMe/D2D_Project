#pragma once

/**
@namespace DXLib
@brief  Direct2Dのライブラリーをなすコンテンツ達の集まり
*/
namespace DXLib
{
	/**
	@class Random
	@brief 乱数を派生してくれる静的関数の集まり
	*/
	class Random
	{
	public:
		static int GetInt(void);
		static float GetFloat(void);
		static int ToInt(int max);
		static int RangeInt(int min, int max);
		static float ToFloat(float max);
		static float RangeFloat(float min, float max);
	};
}