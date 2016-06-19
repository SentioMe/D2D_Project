#include "SentioD2D.h"
#include "Logger.h"

namespace SentioD2DLib
{
	Logger::Logger(void)
	{
		SYSTEMTIME systemTime;
		GetLocalTime(&systemTime);

		bool isPosted = systemTime.wHour >= 12;
		if (isPosted)
			systemTime.wHour -= 12;

		std::string systemTimeString = ExtendString::NumToString(systemTime.wYear, 4);
		systemTimeString.append(ExtendString::NumToString(systemTime.wMonth, 2));
		systemTimeString.append(ExtendString::NumToString(systemTime.wDay, 2));
		systemTimeString.append((isPosted) ? " - PM" : " - AM");
		systemTimeString.append(" Hr" + ExtendString::NumToString(systemTime.wHour, 2));
		systemTimeString.append("Min" + ExtendString::NumToString(systemTime.wMinute, 2));
		systemTimeString.append("Sec" + ExtendString::NumToString(systemTime.wSecond, 2));
		systemTimeString.append("ms" + ExtendString::NumToString(systemTime.wMilliseconds, 3));

		systemTimeString.append(".txt");

		_logFile.open(ExtendString::Format(
			"%s\\Logs\\%s", 
			Application::Instance().GetProjectPath().c_str(), 
			systemTimeString.c_str()).c_str(),
			std::fstream::out);

		Log("Create a instacne of Logger", __FILE__, __FUNCTION__, __LINE__);
	}

	Logger::~Logger(void)
	{
		LOG("Destroy a instance of Logger");
		_logFile.close();
	}

	void Logger::Log(const char* message, const char* file, const char* fuction, int line)
	{
		_Write(LOG_TYPE::NONE, message, ExtendString::Format("%s (at %s : %d)", fuction, file, line).c_str());
	}

	void Logger::LogWarning(const char* message, const char* file, const char* fuction, int line)
	{
		_Write(LOG_TYPE::WARNING_LOG, message, ExtendString::Format("%s (at %s : %d)", fuction, file, line).c_str());
	}

	void Logger::LogError(const char* message, const char* file, const char* fuction, int line)
	{
		_Write(LOG_TYPE::ERROR_LOG, message, ExtendString::Format("%s (at %s : %d)", fuction, file, line).c_str());
		Application::Instance().Stop();
	}

	void Logger::_Write(LOG_TYPE logType, const char* message, const char* location)
	{
#define LOG_LINE "-----------------------------------------------------------\n"
#define LOG_LINE_SIZE 60

		_logFile.write(LOG_LINE, LOG_LINE_SIZE);
		_logFile.flush();

		std::string logTypeString;
		switch (logType)
		{
		case SentioD2DLib::Logger::WARNING_LOG:
			logTypeString = "Logger.LogWarning()";
			break;
		case SentioD2DLib::Logger::ERROR_LOG:
			logTypeString = "Logger.LogError()";
			break;
		case SentioD2DLib::Logger::NONE:
			logTypeString = "Logger.Log()";
			break;
		}
		
		std::string log = ExtendString::Format(
			"[%s] : %s\n%s\n%s\n",
			_GetSystemTime().c_str(), message, logTypeString.c_str(), location);

		_logFile.write(log.c_str(), log.size());
		_logFile.flush();

		_logFile.write(LOG_LINE, LOG_LINE_SIZE);
		_logFile.flush();
	}

	std::string Logger::_GetSystemTime(void)
	{
		SYSTEMTIME systemTime;
		GetLocalTime(&systemTime);

		bool isPosted = systemTime.wHour >= 12;
		if (isPosted)
			systemTime.wHour -= 12;

		std::string systemTimeString = ExtendString::NumToString(systemTime.wYear, 4);
		systemTimeString.append('/' + ExtendString::NumToString(systemTime.wMonth, 2));
		systemTimeString.append('/' + ExtendString::NumToString(systemTime.wDay, 2));
		systemTimeString.append((isPosted) ? " - PM" : " - AM");
		systemTimeString.append(' ' + ExtendString::NumToString(systemTime.wHour, 2));
		systemTimeString.append(':' + ExtendString::NumToString(systemTime.wMinute, 2));
		systemTimeString.append(':' + ExtendString::NumToString(systemTime.wSecond, 2));
		systemTimeString.append(':' + ExtendString::NumToString(systemTime.wMilliseconds, 3));

		return systemTimeString;
	}

}