#include "SentioD2D.h"
#include "Size.h"

namespace SentioD2DLib
{
	Size::Size(const Vector2& vec2)
		: width(vec2.x), height(vec2.y)
	{
	}


	//#########################################################################
#pragma region Operator Function
	Size& Size::operator = (const Size& size)
	{
		this->width = size.width;
		this->height = size.height;

		return *this;
	}

	bool Size::operator==(const Size& size)
	{
		return ExtendMath::Approximately(this->width, size.width)
			&& ExtendMath::Approximately(this->height, size.height);
	}
	bool Size::operator!=(const Size& size)
	{
		return !(*this == size);
	}

	Size& Size::operator*= (int d)
	{
		this->width *= d;
		this->height *= d;

		return *this;
	}
	Size Size::operator*(int d)
	{
		Size size(*this);
		return size *= d;
	}

	Size& Size::operator*=(float d)
	{
		this->width *= d;
		this->height *= d;

		return *this;
	}
	Size Size::operator*(float d)
	{
		Size size(*this);
		return size *= d;
	}

	Size& Size::operator/=(int d)
	{
		this->width /= d;
		this->height /= d;

		return *this;
	}
	Size Size::operator/(int d)
	{
		Size size(*this);
		return size /= d;
	}

	Size& Size::operator/=(float d)
	{
		this->width /= d;
		this->height /= d;

		return *this;
	}
	Size Size::operator/(float d)
	{
		Size size(*this);
		return size /= d;
	}

	Size& Size::operator+=(const Size& size)
	{
		this->width += size.width;
		this->height += size.height;

		return *this;
	}
	Size Size::operator+(const Size& size)
	{
		Size s(*this);
		return s += size;
	}

	Size& Size::operator-=(const Size& size)
	{
		this->width -= size.width;
		this->height -= size.height;

		return *this;
	}
	Size Size::operator-(const Size& size)
	{
		Size s(*this);
		return s -= size;
	}
	Size::operator D2D1_SIZE_F(void)
	{
		return D2D1::SizeF(width, height);
	}

#pragma endregion
//#########################################################################

//#########################################################################
#pragma region Serialize Function
	bool Size::Serialize(const char* filePath)
	{
		XMLSerializer* serializer = new XMLSerializer(filePath);

		if (false == Serialize(serializer))
			return serializer->Close();

		serializer->Save();

		return serializer->Close();
	}
	bool Size::Serialize(XMLSerializer* serializer)
	{
		serializer->Write("Width", this->width);
		serializer->Write("Height", this->height);

		return true;
	}
	bool Size::Deserialize(const char* filePath)
	{
		XMLSerializer* serializer = XMLSerializer::Load(filePath);
		if (serializer == nullptr)
			return false;

		this->Deserialize(serializer);

		return serializer->Close();
	}
	bool Size::Deserialize(XMLSerializer* serializer)
	{
		serializer->Read("Width", this->width);
		serializer->Read("Height", this->height);

		return true;
	}
#pragma endregion
//#########################################################################

	const Size Size::Zero(0.0f, 0.0f);
	const Size Size::One(1.0f, 1.0f);
}