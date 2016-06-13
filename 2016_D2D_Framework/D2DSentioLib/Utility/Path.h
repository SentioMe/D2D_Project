#pragma once

#ifndef __DXLIB_PATH_H__
#define __DXLIB_PATH_H__
/**
@namespace DXLib
@brief  Direct2Dのライブラリーをなすコンテンツ達の集まり
*/
namespace DXLib
{
	/**
	@class Path
	@brief ファイルのパスなどの処理を支援する静的関数の集まり
	*/
	class Path sealed
	{
	private:
		static int _GetFileNameStartPosition(const std::string& path);

	public:
		/** アプリケーションが実行されたパスを返します。*/
		static std::string RunningPath(void);
		/** ソリューション以下のリソースのフォルダまでのパスを返します。*/
		static std::string ResourcesPath(void);

		/** 渡されたパスからファイル名を除いたパスを返します。*/
		static std::string Directory(const std::string& path);
		/** 渡されたパスからファイル名を返します。*/
		static std::string FileName(const std::string& path);
		/** 渡されたパスから拡張子を除いたファイル名を返します。*/
		static std::string FileNameWithoutExtension(const std::string& path);
		/** 渡されたパスから拡張子を返します。*/
		static std::string Extension(const std::string& path);
	};

}

#endif //!__DXLIB_PATH_H__