#pragma once

#ifndef __SENTIO_D2DLIB_DIRECTORY_H__
#define __SENTIO_D2DLIB_DIRECTORY_H__
/**
@namespace SentioD2DLib
@brief  Direct2Dのライブラリーをなすコンテンツ達の集まり
*/
namespace SentioD2DLib
{
	class Directory sealed
	{
	public:
		enum SearchOption
		{
			TOP_DIRECTORY_ONLY,
			ALL_DIRECTORIES,
		};
	public:
		/** 渡されたパスでドライブのすぐ下のパスまでを返します。*/
		static std::string Root(const std::string& path);
		/** 渡されたパスの親パスを返します。*/
		static std::string Parent(const std::string& path);

		static std::vector<std::string> GetFiles(
			const std::string& searchPath, SearchOption searchOption = SearchOption::TOP_DIRECTORY_ONLY);

		static std::vector<std::string> GetFiles(
			const std::string& searchPath, const std::string& searchFilter, SearchOption searchOption = SearchOption::TOP_DIRECTORY_ONLY);

	private:
		static void _AddFilePaths(
			const std::string& searchPath, const std::string& searchFilter, SearchOption searchOption, std::vector<std::string>& fileList);
	};
}

#endif