#pragma once

namespace DXLib
{
	class MathUtil
	{
	public:
		static const float PI;
		static const float PI2;
		static const float Epsilon;

	public:
		static float Degree(float radian);
		static float Radian(float degree);
	};
}