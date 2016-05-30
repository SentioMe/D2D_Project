#pragma once

#ifndef __DXLIB_VECTOR2_H__
#define __DXLIB_VECTOR2_H__

/**
@namespace DXLib
@brief  Direct2Dのライブラリーをなすコンテンツ達の集まり
*/
namespace DXLib
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
		std::string		ToString(void)	const override;
#pragma endregion
//#########################################################################

//#########################################################################
#pragma region Serialize Function
		bool Serialize(const char* filePath);
		bool Serialize(XMLSerializer* serializer);
		bool Deserialize(const char* filePath);
		bool Deserialize(XMLSerializer* serializer);
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

#endif //!__DXLIB_VECTOR2_H__