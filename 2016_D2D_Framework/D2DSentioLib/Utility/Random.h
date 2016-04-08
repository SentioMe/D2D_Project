#pragma once

namespace DXLib
{
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