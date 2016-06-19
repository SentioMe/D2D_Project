#pragma once

#ifdef DEBUG
#define LOG(log)  SentioD2DLib::Logger::Instance().Log(log, __FILE__, __FUNCTION__, __LINE__)
#define LOG_WARNING(log) SentioD2DLib::Logger::Instance().LogWarning(log, __FILE__, __FUNCTION__, __LINE__)
#else
#define LOG(log)
#define LOG_WARNING(log)
#endif

#define LOG_ERROR(log)  SentioD2DLib::Logger::Instance().LogError(log, __FILE__, __FUNCTION__, __LINE__)

#ifndef __SENTIO_D2DLIB_LOGGER_H__
#define __SENTIO_D2DLIB_LOGGER_H__
/**
@namespace SentioD2DLib
@brief  Direct2Dのライブラリーをなすコンテンツ達の集まり
*/
namespace SentioD2DLib
{
	class Logger sealed : public Singleton<Logger>
	{
	private:
		enum LOG_TYPE
		{
			WARNING_LOG,
			ERROR_LOG,
			NONE
		};

	public:
		Logger(void);
		virtual~Logger(void) override;

		void Log(const char* message, const char* file, const char* fuction, int line);
		void LogWarning(const char* message, const char* file, const char* fuction, int line);
		void LogError(const char* message, const char* file, const char* fuction, int line);

	private:
		std::string _GetSystemTime(void);
		void _Write(LOG_TYPE logType, const char* message, const char* location);
	private:
		std::fstream _logFile;
	};

}

#endif //!__SENTIO_D2DLIB_LOGGER_H__