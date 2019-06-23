#include "tauruspch.h"
#include "Log.h"

#include "spdlog/sinks/stdout_color_sinks.h"

namespace Taurus
{
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Initialize()
	{
		// Log pattern
		spdlog::set_pattern("%^[%T] %n: %v%$"); // HH:MM:SS format

		// Engine name and log level
		s_CoreLogger = spdlog::stdout_color_mt("TAURUS");
		s_CoreLogger->set_level(spdlog::level::trace);
		
		// Client name and log level
		s_ClientLogger = spdlog::stdout_color_mt("APPLICATION");
		s_ClientLogger->set_level(spdlog::level::trace);
	}
}
