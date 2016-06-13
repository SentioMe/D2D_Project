#include "SentioD2D.h"
#include "ExtendMath.h"

namespace DXLib
{
	
//#########################################################
#pragma region Const Value

	const float ExtendMath::PI = 3.141592654f;
	const float ExtendMath::PI2 = (PI * 2);
	const float ExtendMath::Unit_Radian = (180.0f / ExtendMath::PI);
	const float ExtendMath::Unit_Degree = (ExtendMath::PI / 180.0f);
	const float ExtendMath::Epsilon = 1.192092896e-07f;

#pragma endregion
//#########################################################

//#########################################################
#pragma region Convert Methode

	float ExtendMath::DegreeToRadian(float degree)
	{
		return (degree * ExtendMath::Unit_Radian);
	}
	float ExtendMath::RadianToDegree(float radian)
	{
		return (radian * ExtendMath::Unit_Degree);
	}

#pragma endregion
//#########################################################


//#########################################################
#pragma region Rect Support Methode
	float ExtendMath::GetRectWidth(const RECT& rect)
	{
		return rect.right - rect.left;
	}
	float ExtendMath::GetRectHeight(const RECT& rect)
	{
		return rect.bottom - rect.top;
	}
	float ExtendMath::GetRectCenterPositionX(const RECT& rect)
	{
		return rect.left + (ExtendMath::GetRectWidth(rect) / 2);
	}
	float ExtendMath::GetRectCenterPositionY(const RECT& rect)
	{
		return rect.top + (ExtendMath::GetRectHeight(rect) / 2);
	}
#pragma endregion
//#########################################################

	bool ExtendMath::Approximately(float lhs, float rhs)
	{
		return abs(lhs - rhs) < ExtendMath::Epsilon ? true : false;
	}
}