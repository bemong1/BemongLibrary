#pragma once
#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE
#include "spdlog/spdlog.h"
#include "spdlog/async.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/rotating_file_sink.h"
#include "spdlog/sinks/dist_sink.h"
#include "spdlog/sinks/msvc_sink.h"
#include "spdlog/sinks/daily_file_sink.h"

#include <iostream>

class Logger
{
private:
	std::shared_ptr<spdlog::logger> m_logger;
	void Init();
	
	const std::string m_strLogPath = "logs/VtkSimulator.log";
	const int m_nMaxSize = 1024 * 1024 * 10;
	const int m_nMaxFileCount = 10;
	const std::string m_strLoggerName = "VtkSimulator";
	const std::string m_strLogPattern = "%Y-%m-%d %X.%e \t [%^%l%$ |  (thread %t) %s <%!> : %#] > \t%v";

public:
	Logger();
	~Logger();

	//Source information(%@, %s, %g, %#, %!) do not appear when using it.
	template <typename... T> void Error(T... arg) { m_logger->error(arg...); };
	template <typename... T> void Warn(T... arg) { m_logger->warn(arg...); };
	template <typename... T> void Info(T... arg) { m_logger->info(arg...); };
	template <typename... T> void Debug(T... arg) { m_logger->debug(arg...); };
	template <typename... T> void Critical(T... arg) { m_logger->critical(arg...); };
	template <typename... T> void Trace(T... arg) { m_logger->trace(arg...); };
};

//#define SPd_INFO(...)	 ::Logger::GetConsoleLogger()->info(__VA_ARGS__);SPDLOG_INFO(__VA_ARGS__); ::Logger::GetFileLogger()->info(__VA_ARGS__);
#define SPd_ERROR(...)		SPDLOG_ERROR(__VA_ARGS__)
#define SPd_WARN(...)		SPDLOG_WARN(__VA_ARGS__)
#define SPd_INFO(...)		SPDLOG_INFO(__VA_ARGS__)
#define SPd_DEBUG(...)		SPDLOG_DEBUG(__VA_ARGS__)
#define SPd_CRITICAL(...)	SPDLOG_CRITICAL(__VA_ARGS__)
#define SPd_TRACE(...)		SPDLOG_TRACE(__VA_ARGS__)