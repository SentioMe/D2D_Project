#include "SentioD2D.h"
#include "Path.h"


namespace DXLib
{
#define BUFFER_SIZE 256
#define NPOS -1

	std::string Path::RunningPath(void)
	{
		char path[BUFFER_SIZE];
		memset(path, 0, BUFFER_SIZE);
		GetModuleFileNameA(NULL, path, BUFFER_SIZE);

		return path;
	}

	std::string Path::ResourcesPath(void)
	{

		std::string root = Path::Root(Path::RunningPath());
		std::string path = Path::RunningPath();

		if (path.find(".exe") != std::string::npos)
		{
			path = Path::Parent(path);
			if (path.find("Debug") != std::string::npos || path.find("Release") != std::string::npos)
			{
				path = Path::Parent(path);
				if (path.find("x64") != std::string::npos || path.find("x86") != std::string::npos)
				{
					path = Path::Parent(path);
				}
			}
		}

		path.append("\\Resources");

		return path;
	}

	std::string Path::Root(const std::string& path)
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

	std::string Path::Parent(const std::string& path)
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

	std::string Path::Directory(const std::string& path)
	{
		assert(path.empty() == false, "Passed path string is empty");
	
		int position = _GetFileNameStartPosition(path);

		if (position != NPOS)
		{
			std::string resultPath;
			resultPath.assign(path.c_str(), position);
			return resultPath;
		}

		return path;
	}

	std::string Path::FileName(const std::string& path)
	{
		assert(path.empty() == false, "Passed path string is empty");

		int position = _GetFileNameStartPosition(path);

		if (position != NPOS)
		{
			++position;
			std::string resultPath;
			resultPath.assign(path.c_str(), position, path.length() - position);
			return resultPath;
		}

		return path;
	}

	std::string Path::Extension(const std::string& path)
	{
		assert(path.empty() == false, "Passed path string is empty");
		int position = NPOS;
		for (int i = path.length() - 1; i >= 0; --i)
		{
			if (path[i] == '.')
			{
				position = i;
				break;
			}
		}

		if (position != NPOS)
		{
			std::string resultPath;
			resultPath.assign(path.c_str(), position, path.length() - position);
			return resultPath;
		}

		return ExtendString::EMPTY;
	}

	int Path::_GetFileNameStartPosition(const std::string& path)
	{
		bool checkedExtension = false;

		for (int i = path.length() - 1; i >= 0; --i)
		{
			if (path[i] == '.')
			{
				checkedExtension = true;
				continue;
			}

			if (true == checkedExtension && (path[i] == '/' || path[i] == '\\'))
				return i;
		}

		return NPOS;
	}

}