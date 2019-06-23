#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Taurus
{
	class TAURUS_API Log
	{
	public:
		static void Initialize();

		inline static std::shared_ptr<spdlog::logger> &GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger> &GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Log initialization macro
#define TAURUS_LOG_INITIALIZE()   Taurus::Log::Initialize()

// Core log macros
#define TAURUS_CORE_TRACE(...)    ::Taurus::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define TAURUS_CORE_INFO(...)     ::Taurus::Log::GetCoreLogger()->info(__VA_ARGS__)
#define TAURUS_CORE_WARN(...)     ::Taurus::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define TAURUS_CORE_ERROR(...)    ::Taurus::Log::GetCoreLogger()->error(__VA_ARGS__)
#define TAURUS_CORE_CRITICAL(...) ::Taurus::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define TAURUS_TRACE(...)         ::Taurus::Log::GetClientLogger()->trace(__VA_ARGS__)
#define TAURUS_INFO(...)          ::Taurus::Log::GetClientLogger()->info(__VA_ARGS__)
#define TAURUS_WARN(...)          ::Taurus::Log::GetClientLogger()->warn(__VA_ARGS__)
#define TAURUS_ERROR(...)         ::Taurus::Log::GetClientLogger()->error(__VA_ARGS__)
#define TAURUS_CRITICAL(...)      ::Taurus::Log::GetClientLogger()->critical(__VA_ARGS__)
