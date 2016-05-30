#include "SentioD2D.h"
#include "Vector2.h"


namespace DXLib
{
//#########################################################################
#pragma region Operator Function
	Vector2& Vector2::operator = (const Vector2& vec2)
	{
		this->x = vec2.x;
		this->y = vec2.y;

		return *this;
	}

	bool Vector2::operator==(const Vector2& vec2)
	{
		return (x == vec2.x && y == vec2.y);
	}
	bool Vector2::operator!=(const Vector2& vec2)
	{
		return !(*this == vec2);
	}

	Vector2& Vector2::operator*=(int d)
	{
		x *= d;
		y *= d;

		return *this;
	}
	Vector2 Vector2::operator*(int d)
	{
		Vector2 v(*this);
		return v *= d;
	}

	Vector2& Vector2::operator*=(float d)
	{
		x *= d;
		y *= d;

		return *this;
	}
	Vector2 Vector2::operator*(float d)
	{
		Vector2 v(*this);
		return v *= d;
	}

	Vector2& Vector2::operator/=(int d)
	{
		x /= d;
		y /= d;

		return *this;
	}
	Vector2 Vector2::operator/(int d)
	{
		Vector2 v(*this);
		return v /= d;
	}

	Vector2& Vector2::operator/=(float d)
	{
		x /= d;
		y /= d;

		return *this;
	}
	Vector2 Vector2::operator/(float d)
	{
		Vector2 v(*this);
		return v /= d;
	}

	Vector2& Vector2::operator+=(const Vector2& vec2)
	{
		x += vec2.x;
		y += vec2.y;

		return *this;
	}
	Vector2 Vector2::operator+(const Vector2& vec2)
	{
		Vector2 v(*this);
		return v += vec2;
	}

	Vector2& Vector2::operator-=(const Vector2& vec2)
	{
		x -= vec2.x;
		y -= vec2.y;

		return *this;
	}
	Vector2 Vector2::operator-(const Vector2& vec2)
	{
		Vector2 v(*this);
		return v -= vec2;
	}
	Vector2::operator D2D1_POINT_2F(void)
	{
		return D2D1::Point2F(x, y);
	}
#pragma endregion
//#########################################################################

//#########################################################################
#pragma region Convert Function
	std::string	Vector2::ToString(void) const
	{
		return ExtendString::Format("x : %.2f, y : %.2f", x, y);
	}
#pragma endregion
//#########################################################################

//#########################################################################
#pragma region Serialize Function
	bool Vector2::Serialize(const char* filePath)
	{
		XMLSerializer* serializer = new XMLSerializer(filePath);

		if (false == Serialize(serializer))
			return serializer->Close();

		serializer->Save();

		return serializer->Close();
	}
	bool Vector2::Serialize(XMLSerializer* serializer)
	{
		serializer->Write("X", this->x);
		serializer->Write("Y", this->y);

		return true;
	}
	bool Vector2::Deserialize(const char* filePath)
	{
		XMLSerializer* serializer = XMLSerializer::Load(filePath);

		this->Deserialize(serializer);

		return serializer->Close();
	}
	bool Vector2::Deserialize(XMLSerializer* serializer)
	{
		serializer->Read("X", this->x);
		serializer->Read("Y", this->y);

		return true;
	}
#pragma endregion
//#########################################################################

	void Vector2::Normalize(void)
	{
		*this /= Length();
	}
	Vector2 Vector2::GetNormalized(void)
	{
		Vector2 vec2(*this);
		vec2.Normalize();

		return vec2;
	}

	float Vector2::Length(void)
	{
		return sqrtf(SqLength());
	}
	float Vector2::SqLength(void)
	{
		return x * x + y * y;
	}

	float Vector2::Distance(const Vector2& vec2)
	{
		Vector2 v(vec2);
		v -= (*this);

		return v.Length();
	}

	float Vector2::Dot(const Vector2& v1, const Vector2& v2)
	{
		return v1.x * v2.x + v1.y * v2.y;
	}

	float Vector2::Cross(const Vector2& v1, const Vector2& v2)
	{
		return v1.x * v2.y - v1.y * v2.x;
	}

	Vector2& Vector2::Clamp(const Vector2& _min, const Vector2& _max)
	{
		assert(!(_min.x > _max.x || _min.y > _max.y));

		x = (x < _min.x) ? _min.x : (x > _max.x) ? _max.x : x;
		y = (y < _min.y) ? _min.y : (y > _max.y) ? _max.y : y;

		return *this;
	}

	const Vector2 Vector2::Zero(0.0f, 0.0f);
	const Vector2 Vector2::One(1.0f, 1.0f);
	const Vector2 Vector2::Up(0.0f, 1.0f);
	const Vector2 Vector2::Down(0.0f, -1.0f);
	const Vector2 Vector2::Right(1.0f, 0.0f);
	const Vector2 Vector2::Left(-1.0f, 0.0f);

}