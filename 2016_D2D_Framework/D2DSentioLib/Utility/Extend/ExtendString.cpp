#include "SentioD2D.h"
#include "ExtendString.h"
#include <codecvt>

namespace DXLib
{
//#########################################################
#pragma region Const Value
	const std::string ExtendString::STRING_EMPTY = "";
	const std::wstring ExtendString::WSTRING_EMPTY = L"";
#pragma endregion
//#########################################################

//#########################################################
#pragma region Convert Methode
	const std::string& ExtendString::WStringToString(IN const std::wstring & input)
	{
		std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
		return converter.to_bytes(input);
	}

	const std::wstring& ExtendString::StringToWString(IN const std::string & input)
	{
		std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
		return converter.from_bytes(input);
	}
#pragma endregion
//#########################################################

//#########################################################
#pragma region Adjust Methode
	std::string ExtendString::Format(const char * format, ...)
	{
#define STRING_MAX_BUFFER_SIZE 1024
		std::string ret;

		va_list ap;
		va_start(ap, format);

		char* buf = (char*)malloc(STRING_MAX_BUFFER_SIZE);
		if (buf != nullptr)
		{
			vsnprintf(buf, STRING_MAX_BUFFER_SIZE, format, ap);
			ret = buf;
			free(buf);
		}

		va_end(ap);

		return ret;
	}

	void ExtendString::Trim(OUT std::wstring & output, OPTIONAL bool left, OPTIONAL bool right)
	{
		static const std::wstring delimiter = L"\t\r\n";

		if (true == right)
		{
			output.erase(output.find_last_not_of(delimiter) + 1);
		}

		if (true == left)
		{
			output.erase(0, output.find_first_not_of(delimiter));
		}
	}

	void ExtendString::Trim(OUT std::string & output, OPTIONAL bool left, OPTIONAL bool right)
	{
		static const std::string delimiter = "\t\r\n";

		if (true == right)
		{
			output.erase(output.find_last_not_of(delimiter) + 1);
		}

		if (true == left)
		{
			output.erase(0, output.find_first_not_of(delimiter));
		}
	}
#pragma endregion
//#########################################################

}
