#include "SentioD2D.h"
#include "ExtendString.h"
#include <codecvt>

namespace DXLib
{
#define STRING_MAX_BUFFER_SIZE 256

	const std::string ExtendString::EMPTY = "";
	
	/** wstringタイプの文字列の変数を stringタイプで変換します。*/
	std::string ExtendString::ToString(const std::wstring& input)
	{
		std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
		return converter.to_bytes(input);
	}

	/** stringタイプの文字列の変数を wstringタイプで変換します。*/
	std::wstring ExtendString::ToWString(const std::string& input)
	{
		std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
		return converter.from_bytes(input);
	}

	

	/** 文字列の形式に合わせて、伝達されたパラメータ達を一つの文字列でへんかんします。*/
	std::string ExtendString::Format(const char* format, ...)
	{
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

	/** 文字列の両断から必要ない空白を削除します。*/
	void ExtendString::Trim(OUT std::string& output, OPTIONAL bool left, OPTIONAL bool right)
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
}
