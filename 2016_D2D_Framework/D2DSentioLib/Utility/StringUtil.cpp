#include "SentioD2D.h"
#include "StringUtil.h"
#include <codecvt>

namespace DXLib
{
//#########################################################
#pragma region Const Value
	const std::string StringUtil::STRING_EMPTY = "";
	const std::wstring StringUtil::WSTRING_EMPTY = L"";
#pragma endregion
//#########################################################

//#########################################################
#pragma region Convert Methode
	void StringUtil::WStringToString(OUT std::string & output_, IN const std::wstring & input_)
	{
		output_.clear();

		std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
		output_ = converter.to_bytes(input_);

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

		std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
		output_ = converter.from_bytes(input_);
	}

	const std::wstring StringUtil::StringToWString(IN const std::string & input_)
	{
		std::wstring output;

		StringUtil::StringToWString(output, input_);

		return output;
	}
#pragma endregion
//#########################################################

//#########################################################
#pragma region Adjust Methode
	std::string StringUtil::Format(const char * format_, ...)
	{
#define STRING_MAX_BUFFER_SIZE 1024
		std::string ret;

		va_list ap;
		va_start(ap, format_);

		char* buf = (char*)malloc(STRING_MAX_BUFFER_SIZE);
		if (buf != nullptr)
		{
			vsnprintf(buf, STRING_MAX_BUFFER_SIZE, format_, ap);
			ret = buf;
			free(buf);
		}

		va_end(ap);

		return ret;
	}

	void StringUtil::Trim(OUT std::wstring & output_, OPTIONAL bool left_, OPTIONAL bool right_)
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

	void StringUtil::Trim(OUT std::string & output_, OPTIONAL bool left_, OPTIONAL bool right_)
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
#pragma endregion
//#########################################################

}
