#pragma once


#ifndef __SENTIO_D2DLIB_SIZE_H__
#define __SENTIO_D2DLIB_SIZE_H__

/**
@namespace SentioD2DLib
@brief  Direct2Dのライブラリーをなすコンテンツ達の集まり
*/
namespace SentioD2DLib
{
	class Vector2;

	class Size : public IConvertible, public IXMLSerializable
	{
	public:
		Size(void)
			: width(0.f), height(0.f)
		{
		}
		Size(float _width, float _height)
			: width(_width), height(_height)
		{
		}
		Size(const D2D1_SIZE_F& size)
			: width(size.width), height(size.height)
		{
		}
		explicit Size(const Vector2& vec2);

//#########################################################################
#pragma region Operator Function
		Size& operator=(const Size& vec2);
		bool operator==(const Size& vec2);
		bool operator!=(const Size& vec2);
		Size& operator*=(int d);
		Size operator*(int d);
		Size& operator*=(float d);
		Size operator*(float d);
		Size& operator/=(int d);
		Size operator/(int d);
		Size& operator/=(float d);
		Size operator/(float d);
		Size& operator+=(const Size& vec2);
		Size operator+(const Size& vec2);
		Size& operator-=(const Size& vec2);
		Size operator-(const Size& vec2);
		operator D2D1_SIZE_F(void);
#pragma endregion
//#########################################################################

//#########################################################################
#pragma region Convert Funtion
		std::string	ToString(void) const override
		{ return ExtendString::Format("width : %.2f, height : %.2f", width, height); }
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
	
		static const Size Zero;
		static const Size One;
	public:
		float width;
		float height;
	};

}
#endif //!__SENTIO_D2DLIB_SIZE_H__