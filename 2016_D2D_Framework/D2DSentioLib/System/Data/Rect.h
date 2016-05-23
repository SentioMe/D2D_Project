#pragma once

#ifndef __DXLIB_RECT_H__
#define __DXLIB_RECT_H__
/**
@namespace DXLib
@brief  Direct2Dのライブラリーをなすコンテンツ達の集まり
*/
namespace DXLib
{
	class Vector2;
	class Size;

	class Rect : public IXMLSerializable
	{
	public:
		Rect(void);
		Rect(float _x, float _y, float _width, float _height);
		Rect(const D2D1_RECT_F& rect);
		Rect(const RECT& rect);

//#########################################################################
#pragma region Serialize Function
		bool Serialize(const char* filePath);
		bool Serialize(XMLSerializer* serializer);
		bool Deserialize(const char* filePath);
		bool Deserialize(XMLSerializer* serializer);
#pragma endregion
//#########################################################################


//#########################################################################
#pragma region Operator Function
		Rect& operator=(const Rect& rect);
		bool operator==(const Rect& rect);
		bool operator!=(const Rect& rect);
		operator D2D1_RECT_F(void);
		operator RECT(void);
#pragma endregion
//#########################################################################

		float Left(void) const;
		float Right(void) const;
		float Top(void) const;
		float Bottom(void) const;
		float MiddleH(void) const;
		float MiddleV(void) const;

		bool IsContains(const Vector2& point) const;
		bool IsIntersects(const Rect& rect) const;

		void Merge(const Rect& rect);

		static const Rect Zero;
	public:
		Vector2 origin;
		Size size;
	};

}
#endif