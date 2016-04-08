#include "SentioD2D.h"
#include "StringUtil.h"

namespace DXLib
{
	const std::string StringUtil::STRING_EMPTY = "";
	const std::wstring StringUtil::WSTRING_EMPTY = L"";

	void StringUtil::WStringToString(OUT std::string & output_, IN const std::wstring & input_)
	{
		if (&input_ == NULL)
		{
			output_ = "";
			return;
		}

		size_t size = input_.size();
		output_.resize(size);

		for (size_t i = 0; i < size; ++i)
		{
			//string변수에 맨 뒤에서부터 현재 wstring의 문자를 형변환 시켜 채운다
			//이때 0xFF(11111111)와 비트연산을 한다
			//-> 1과 연산하므로 현재 값은 손실시키지 않으면서, 8비트 형으로 변환되므로 wstrig값이 된다
			output_[i] = static_cast<const char>(input_[i] & 0xFF);
		}

	}

	const std::string StringUtil::WStringToString(IN const std::wstring & input_)
	{
		std::string output;

		StringUtil::WStringToString(output, input_);

		return output;
	}

	void StringUtil::StringToWString(OUT std::wstring & output_, IN const std::string & input_)
	{
		output_.clear();

		if (&input_ == NULL)
		{
			output_ = L"";
			return;
		}

		size_t size = output_.size();
		output_.resize(size);

		for (size_t i = 0; i < size; ++i)
		{
			output_[i] = static_cast<const wchar_t>(input_[i]);
		}
	}

	const std::wstring StringUtil::StringToWString(IN const std::string & input_)
	{
		std::wstring output;

		StringUtil::StringToWString(output, input_);

		return output;
	}

	void StringUtil::TrimWString(OUT std::wstring & output_, OPTIONAL bool left_, OPTIONAL bool right_)
	{
		static const std::wstring delimiter = L"\t\r\n";

		if (true == right_)
		{
			output_.erase(output_.find_last_not_of(delimiter) + 1);
		}

		if (true == left_)
		{
			output_.erase(0, output_.find_first_not_of(delimiter));
		}
	}

	void StringUtil::TrimString(OUT std::string & output_, OPTIONAL bool left_, OPTIONAL bool right_)
	{
		static const std::string delimiter = "\t\r\n";

		if (true == right_)
		{
			output_.erase(output_.find_last_not_of(delimiter) + 1);
		}

		if (true == left_)
		{
			output_.erase(0, output_.find_first_not_of(delimiter));
		}
	}

}
