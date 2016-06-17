#include "SentioD2D.h"
#include "Rect.h"

namespace SentioD2DLib
{
	Rect::Rect(void)
		: origin(0.0f, 0.0f), size(0.0f, 0.0f)
	{
	}
	Rect::Rect(float _x, float _y, float _width, float _height)
		: origin(_x, _y), size(_width, _height)
	{
	}
	Rect::Rect(const D2D1_RECT_F& rect)
		: origin(rect.left, rect.top), 
		size(rect.right - rect.left, rect.bottom - rect.top)
	{
	}
	Rect::Rect(const RECT& rect)
		: origin(rect.left, rect.top),
		size(rect.right - rect.left, rect.bottom - rect.top)
	{
	}

//#########################################################################
#pragma region Operator Function
	Rect& Rect::operator=(const Rect& rect)
	{
		this->origin = rect.origin;
		this->size = rect.size;

		return *this;
	}

	bool Rect::operator==(const Rect& rect)
	{
		return (origin == rect.origin && size == rect.size);
	}

	bool Rect::operator!=(const Rect& rect)
	{
		return !(*this == rect);
	}

	Rect::operator D2D1_RECT_F(void)
	{
		return D2D1::RectF(Left(), Top(), Right(), Bottom());
	}

	Rect::operator RECT(void)
	{
		return{ Left(), Top(), Right(), Bottom() };
	}
#pragma endregion
//#########################################################################

//#########################################################################
#pragma region Serialize Function
	bool Rect::Serialize(const char* filePath)
	{
		XMLSerializer* serializer = new XMLSerializer(filePath);

		if (false == Serialize(serializer))
			return serializer->Close();

		serializer->Save();

		return serializer->Close();
	}
	bool Rect::Serialize(XMLSerializer* serializer)
	{
		serializer->Write("Origin", this->origin);
		serializer->Write("Size", this->size);

		return true;
	}
	bool Rect::Deserialize(const char* filePath)
	{
		XMLSerializer* serializer = XMLSerializer::Load(filePath);
		if (serializer == nullptr)
			return false;

		this->Deserialize(serializer);

		return serializer->Close();
	}
	bool Rect::Deserialize(XMLSerializer* serializer)
	{
		serializer->Read("Origin", origin);
		serializer->Read("Size", size);

		return true;
	}
#pragma endregion
//#########################################################################

	float Rect::Left(void) const
	{
		return origin.x;
	}
	float Rect::Right(void) const
	{
		return origin.x + size.width;
	}
	float Rect::Top(void) const
	{
		return origin.y;
	}
	float Rect::Bottom(void) const
	{
		return origin.y + size.height;
	}
	float Rect::MiddleH(void) const
	{
		return origin.x + (size.width * 0.5f);
	}
	float Rect::MiddleV(void) const
	{
		return origin.y + (size.height * 0.5f);
	}

	bool Rect::IsContains(const Vector2& point) const
	{
		return (point.x >= Left() && point.x <= Right()
			&& point.y >= Top() && point.y <= Bottom());
	}
	bool Rect::IsIntersects(const Rect& rect) const
	{
		return !(
			Right() < rect.Left() ||
			rect.Right() < Left() ||
			Bottom() < rect.Top() ||
			rect.Bottom() < Top());
	}

	void Rect::Merge(const Rect& rect)
	{
		float left = min(Left(), rect.Left());
		float right = max(Right(), rect.Right());
		float top = min(Top(), rect.Top());
		float bottom = max(Bottom(), rect.Bottom());

		origin.x = left;
		origin.y = top;
		size.width = right - left;
		size.height = bottom - top;
	}

	const Rect Rect::Zero(0.0f, 0.0f, 0.0f, 0.0f);
}