﻿#pragma once

/**
@namespace DXLib
@brief  Direct2Dのライブラリーをなすコンテンツ達の集まり
*/
namespace DXLib
{
	/**
	@class ExtendString
	@brief 文字列の使う事をサポートする静的関数の集まり
	*/
	class ExtendString sealed
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
		static const std::string& WStringToString(const std::wstring& input);

		/** stringタイプの文字列の変数を wstringタイプで変換します。*/
		static const std::wstring& StringToWString(const std::string& input);

#pragma endregion
//#########################################################

//#########################################################
#pragma region Adjust Methode

		/** 文字列の形式に合わせて、伝達されたパラメータ達を一つの文字列でへんかんします。*/
		static const std::string& Format(const char* format, ...);

		/** 文字列の両断から必要ない空白を削除します。*/
		static void Trim(OUT std::wstring& output, OPTIONAL bool left = true, OPTIONAL bool right = true);
		static void Trim(OUT std::string& output, OPTIONAL bool left = true, OPTIONAL bool right = true);

#pragma endregion
//#########################################################

	};
}
