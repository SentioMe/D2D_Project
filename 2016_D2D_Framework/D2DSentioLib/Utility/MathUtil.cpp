#include "SentioD2D.h"
#include "MathUtil.h"

namespace DXLib
{
	
//#########################################################
#pragma region Const Value

	const float MathUtil::PI = 3.141592654f;
	const float MathUtil::PI2 = (PI * 2);
	const float MathUtil::Unit_Radian = (180.0f / MathUtil::PI);
	const float MathUtil::Unit_Degree = (MathUtil::PI / 180.0f);
	const float MathUtil::Epsilon = 1.192092896e-07f;

#pragma endregion
//#########################################################

//#########################################################
#pragma region Convert Methode

	float MathUtil::DegreeToRadian(float degree_)
	{
		return (degree_ * MathUtil::Unit_Radian);
	}
	float MathUtil::RadianToDegree(float radian_)
	{
		return (radian_ * MathUtil::Unit_Degree);
	}

#pragma endregion
//#########################################################

}