#include "SentioD2D.h"
#include "Path.h"


namespace DXLib
{
#define BUFFER_SIZE 256


	std::string Path::RunningPath(void)
	{
		char buf[BUFFER_SIZE];
		memset(buf, 0, BUFFER_SIZE);
		GetModuleFileNameA(NULL, buf, BUFFER_SIZE);

		std::string path = buf;
		
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

		return path;
	}

	std::string Path::Parent(std::string path)
	{
		assert(path.empty() == false, "Passed path string is empty");

		int parentPos = path.find_last_of('/');
		if (parentPos == -1)
			parentPos = path.find_last_of('\\');

		if (parentPos != -1)
		{
			std::string parentPath;
			parentPath.assign(path.c_str(), parentPos);
			return parentPath;
		}

		return path;
	}

}