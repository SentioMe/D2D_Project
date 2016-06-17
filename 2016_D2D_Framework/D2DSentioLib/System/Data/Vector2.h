#pragma once

#ifndef __SENTIO_D2DLIB_VECTOR2_H__
#define __SENTIO_D2DLIB_VECTOR2_H__

/**
@namespace SentioD2DLib
@brief  Direct2Dのライブラリーをなすコンテンツ達の集まり
*/
namespace SentioD2DLib
{
	class Vector2 : public IConvertible, public IXMLSerializable
	{
	public:
		Vector2(void)
			: x(0.f), y(0.f)
		{
		}
		Vector2(float _x, float _y)
			: x(_x), y(_y)
		{
		}
		Vector2(const D2D1_POINT_2F& point)
			: x(point.x), y(point.y)
		{
		}

//#########################################################################
#pragma region Operator Function
		Vector2& operator=(const Vector2& vec2);
		bool operator==(const Vector2& vec2);
		bool operator!=(const Vector2& vec2);
		Vector2& operator*=(int d);
		Vector2 operator*(int d);
		Vector2& operator*=(float d);
		Vector2 operator*(float d);
		Vector2& operator/=(int d);
		Vector2 operator/(int d);
		Vector2& operator/=(float d);
		Vector2 operator/(float d);
		Vector2& operator+=(const Vector2& vec2);
		Vector2 operator+(const Vector2& vec2);
		Vector2& operator-=(const Vector2& vec2);
		Vector2 operator-(const Vector2& vec2);
		operator D2D1_POINT_2F(void);
#pragma endregion
//#########################################################################

//#########################################################################
#pragma region Convert Funtion
		std::string ToString(void) const override
		{ return ExtendString::Format("x : %.2f, y : %.2f", x, y); }
#pragma endregion
//#########################################################################

//#########################################################################
#pragma region Serialize Function
		bool Serialize(const char* filePath) override;
		bool Serialize(XMLSerializer* serializer) override;
		bool Deserialize(const char* filePath) override;
		bool Deserialize(XMLSerializer* serializer) override;
#pragma endregion
//#########################################################################

		void Normalize(void);
		Vector2 GetNormalized(void);
		float Length(void);
		float SqLength(void);
		float Distance(const Vector2& vec2);
		static float Dot(const Vector2& v1, const Vector2& v2);
		static float Cross(const Vector2& v1, const Vector2& v2);
		Vector2& Clamp(const Vector2& _min, const Vector2& _max);



		static const Vector2 Zero;
		static const Vector2 One;
		static const Vector2 Up;
		static const Vector2 Down;
		static const Vector2 Right;
		static const Vector2 Left;
	public:
		float x;
		float y;
	};


	typedef Vector2 Point, *Vec2Ptr, *PointPtr;
}

#endif //!__SENTIO_D2DLIB_VECTOR2_H__