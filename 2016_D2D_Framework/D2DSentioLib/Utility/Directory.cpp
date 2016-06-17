#include "SentioD2D.h"
#include "Directory.h"
#include <exception>

#define ALL_FILE_FILTER "*.*"

namespace SentioD2DLib
{
#define BUFFER_SIZE 256
#define NPOS -1

	std::string Directory::Root(const std::string& path)
	{
		assert(path.empty() == false, "Passed path string is empty");

		int position = NPOS;
		for (int i = 0; i < path.length(); ++i)
		{
			if ((path[i] == '/' || path[i] == '\\') && i > 0)
			{
				if (path[i - 1] == ':')
					continue;

				position = i;
				break;
			}
		}

		if (position != NPOS)
		{
			std::string resultPath;
			resultPath.assign(path.c_str(), position);
			return resultPath;
		}

		return path;
	}

	std::string Directory::Parent(const std::string& path)
	{
		assert(path.empty() == false, "Passed path string is empty");

		int position = path.find_last_of('/');
		if (position == NPOS)
			position = path.find_last_of('\\');

		if (position != NPOS)
		{
			std::string resultPath;
			resultPath.assign(path.c_str(), position);
			return resultPath;
		}

		return path;
	}


	std::vector<std::string> Directory::GetFiles(
		const std::string& searchPath, SearchOption searchOption)
	{
		return Directory::GetFiles(searchPath, ALL_FILE_FILTER, searchOption);
	}

	std::vector<std::string> Directory::GetFiles(
		const std::string& searchPath, const std::string& searchFilter, SearchOption searchOption)
	{
		
		std::vector<std::string> fileList;
		
		Directory::_AddFilePaths(searchPath, searchFilter, searchOption, fileList);

		return fileList;
	}

	void Directory::_AddFilePaths(
		const std::string& searchPath, const std::string& searchFilter, SearchOption searchOption, std::vector<std::string>& fileList)
	{
		WIN32_FIND_DATAA fileFindData;

		std::string directory = searchPath + "*";

		HANDLE fileFinderHandler = FindFirstFileA(directory.c_str(), &fileFindData);

		if (fileFinderHandler == INVALID_HANDLE_VALUE)
		{
			FindClose(fileFinderHandler);
			return;
		}

		do
		{
			//폴더의 경우 하위 탐색
			if (fileFindData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
			{
				if (searchOption == SearchOption::TOP_DIRECTORY_ONLY)
					continue;

				if (strcmp(fileFindData.cFileName, ".") == 0 || strcmp(fileFindData.cFileName, "..") == 0)
					continue;

				Directory::_AddFilePaths(searchPath + fileFindData.cFileName + "\\", searchFilter, searchOption, fileList);
				continue;
			}

			std::string extension = "*" + Path::Extension(fileFindData.cFileName);
			if (extension != searchFilter)
				continue;

			fileList.push_back(searchPath + fileFindData.cFileName);

		} while (FindNextFileA(fileFinderHandler, &fileFindData));

		FindClose(fileFinderHandler);
	}

}