#include "Logger.h"

//std::shared_ptr<spdlog::logger> Logger::m_logger;

Logger::Logger()
{
	Init();
}

Logger::~Logger()
{
	SPd_INFO("Logger End!");
}

void Logger::Init()
{
	spdlog::flush_every(std::chrono::seconds(1));
	auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
	console_sink->set_level(spdlog::level::trace);
	auto console_link = std::make_shared<spdlog::sinks::dist_sink_mt>();
	console_link->add_sink(console_link);

	auto file_sink = std::make_shared<spdlog::sinks::rotating_file_sink_mt>(
		m_strLogPath, m_nMaxSize, m_nMaxFileCount);
	file_sink->set_level(spdlog::level::trace);
	auto file_link = std::make_shared < spdlog::sinks::dist_sink_mt>();
	file_link->add_sink(file_sink);

	spdlog::sinks_init_list sink_list = { console_sink, file_sink };

	m_logger = std::make_shared<spdlog::logger>(m_strLoggerName, sink_list);
	//m_logger->set_level(spdlog::level::err);

	int get = spdlog::level::trace;//GetLogLevel();
	switch (get)
	{
	case 0:
		m_logger->set_level(spdlog::level::trace);
		break;
	case 1:
		m_logger->set_level(spdlog::level::debug);
		break;
	case 2:
		m_logger->set_level(spdlog::level::info);
		break;
	case 3:
		m_logger->set_level(spdlog::level::warn);
		break;
	case 4:
		m_logger->set_level(spdlog::level::err);
		break;
	case 5:
		m_logger->set_level(spdlog::level::critical);
		break;
	}

	spdlog::set_default_logger(m_logger);
	spdlog::set_pattern(m_strLogPattern);
}