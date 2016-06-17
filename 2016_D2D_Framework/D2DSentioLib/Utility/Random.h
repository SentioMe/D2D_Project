#pragma once

#ifndef __SENTIO_D2DLIB_RANDOM_H__
#define __SENTIO_D2DLIB_RANDOM_H__
/**
@namespace SentioD2DLib
@brief  Direct2Dのライブラリーをなすコンテンツ達の集まり
*/
namespace SentioD2DLib
{
	/**
	@class Random
	@brief 乱数を派生してくれる静的関数の集まり
	*/
	class Random sealed
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
#endif //!__SENTIO_D2DLIB_RANDOM_H__