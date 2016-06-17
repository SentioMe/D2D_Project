#include "SentioD2D.h"
#include "Random.h"

namespace SentioD2DLib
{
	int Random::GetInt(void)
	{
		return rand() % INT_MAX;
	}
	float Random::GetFloat(void)
	{
		return (FLOAT)(rand()) / (FLOAT)RAND_MAX;
	}
	int Random::ToInt(int max)
	{
		return rand() % max;
	}
	int Random::RangeInt(int min, int max)
	{
		return rand() % (max - min + 1) + min;
	}
	float Random::ToFloat(float max)
	{
		return Random::GetFloat() * max;
	}
	float Random::RangeFloat(float min, float max)
	{
		return Random::GetFloat() * (max - min) + min;
	}
}