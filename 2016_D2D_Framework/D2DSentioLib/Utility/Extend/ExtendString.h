#pragma once

#ifndef __DXLIB_EXTEND_STRING_H__
#define __DXLIB_EXTEND_STRING_H__
/**
@namespace DXLib
@brief  Direct2Dのライブラリーをなすコンテンツ達の集まり
*/
namespace DXLib
{
	typedef std::vector<std::string> StringContainer;

	/**
	@class ExtendString
	@brief 文字列の使う事をサポートする静的関数の集まり
	*/
	class ExtendString sealed
	{
	public:
		static const std::string EMPTY;

	public:
		/** wstringタイプの文字列の変数を stringタイプで変換します。*/
		static std::string ToString(const std::wstring& input);

		/** stringタイプの文字列の変数を wstringタイプで変換します。*/
		static std::wstring ToWString(const std::string& input);

		/** 文字列の形式に合わせて、伝達されたパラメータ達を一つの文字列でへんかんします。*/
		static std::string Format(const char* format, ...);

		/** 文字列の両断から必要ない空白を削除します。*/
		static void Trim(OUT std::string& output, OPTIONAL bool left = true, OPTIONAL bool right = true);


	};
}

#endif //!__DXLIB_EXTEND_STRING_H__