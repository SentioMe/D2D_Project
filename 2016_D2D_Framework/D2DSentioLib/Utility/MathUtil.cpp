#include "SentioD2D.h"
#include "StringUtil.h"
#include "MathUtil.h"

namespace DXLib
{
	const float PI = 3.141592654f;
	const float PI2 = (PI * 2);
	const float Epsilon = 1.192092896e-07f;


	float MathUtil::Degree(float radian)
	{
		return (radian * (180.0f / MathUtil::PI));
	}
	float MathUtil::Radian(float degree)
	{
		return (degree * (MathUtil::PI / 180.0f));
	}
}