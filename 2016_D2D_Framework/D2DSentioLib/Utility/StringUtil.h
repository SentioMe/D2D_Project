#pragma once

/**
@namespace DXLib
@brief  Direct2Dのライブラリーをなすコンテンツ達の集まり
*/
namespace DXLib
{
	/**
	@class StringUtil
	@brief 文字列の使う事をサポートする静的関数の集まり
	*/
	class StringUtil sealed
	{
	public:
//#########################################################
#pragma region Const Value
		static const std::string STRING_EMPTY;
		static const std::wstring WSTRING_EMPTY;
#pragma endregion
//#########################################################

//#########################################################
#pragma region Convert Methode

		/** wstringタイプの文字列の変数を stringタイプで変換します。*/
		static void WStringToString(OUT std::string& output_, IN const std::wstring& input_);
		static const std::string WStringToString(IN const std::wstring& input_);

		/** stringタイプの文字列の変数を wstringタイプで変換します。*/
		static void StringToWString(OUT std::wstring& output_, IN const std::string& input_);
		static const std::wstring StringToWString(IN const std::string& input_);

#pragma endregion
//#########################################################

//#########################################################
#pragma region Adjust Methode

		/** 文字列の形式に合わせて、伝達されたパラメータ達を一つの文字列でへんかんします。*/
		static std::string Format(const char* format_, ...);

		/** 文字列の両断から必要ない空白を削除します。*/
		static void Trim(OUT std::wstring& output_, OPTIONAL bool left_ = true, OPTIONAL bool right_ = true);
		static void Trim(OUT std::string& output_, OPTIONAL bool left_ = true, OPTIONAL bool right_ = true);

#pragma endregion
//#########################################################

	};
}
