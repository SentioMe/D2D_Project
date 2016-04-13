#pragma once

/**
@namespace DXLib
@brief  Direct2Dのライブラリーをなすコンテンツ達の集まり
*/
namespace DXLib
{
	/**
	@class MathUtil
	@brief 算術の演算をサポートする静的関数の集まり
	*/
	class MathUtil
	{
	public:
//#########################################################
#pragma region Const Value

		static const float PI;
		static const float PI2;
		static const float Unit_Radian;
		static const float Unit_Degree;
		static const float Epsilon;

#pragma endregion
//#########################################################
		
//#########################################################
#pragma region Convert Methode

		static float DegreeToRadian(float degree_);
		static float RadianToDegree(float radian_);

#pragma endregion
//#########################################################

	};
}