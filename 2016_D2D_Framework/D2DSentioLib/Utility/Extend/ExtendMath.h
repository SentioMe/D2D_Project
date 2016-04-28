#pragma once

/**
@namespace DXLib
@brief  Direct2Dのライブラリーをなすコンテンツ達の集まり
*/
namespace DXLib
{
	/**
	@class ExtendMath
	@brief 算術の演算をサポートする静的関数の集まり
	*/
	class ExtendMath sealed
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

		static float DegreeToRadian(float degree);
		static float RadianToDegree(float radian);

#pragma endregion
//#########################################################

//#########################################################
#pragma region Rect Support Methode
		static float GetRectWidth(const RECT& rect);
		static float GetRectHeight(const RECT& rect);
		static float GetRectCenterPositionX(const RECT& rect);
		static float GetRectCenterPositionY(const RECT& rect);
#pragma endregion
//#########################################################
		
	};
}