#pragma once

namespace DXLib
{

	class StringUtil
	{
	public:
		static const std::string STRING_EMPTY;
		static const std::wstring WSTRING_EMPTY;

	public:
		//#########################################################
		//wstring => string
		//#########################################################
		static void WStringToString(OUT std::string& output_, IN const std::wstring& input_);
		static const std::string WStringToString(IN const std::wstring& input_);
		//#########################################################
		//string => wstring
		//#########################################################
		static void StringToWString(OUT std::wstring& output_, IN const std::string& input_);
		static const std::wstring StringToWString(IN const std::string& input_);

		//###########################
		//Trimming
		//###########################
		static void TrimWString(OUT std::wstring& output_, OPTIONAL bool left_ = true, OPTIONAL bool right_ = true);
		static void TrimString(OUT std::string& output_, OPTIONAL bool left_ = true, OPTIONAL bool right_ = true);
	};
}
