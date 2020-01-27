#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Royal
{

	class ROYAL_API Log
	{
	public:

		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
	};

}

//Core log macros
#define RL_CORE_TRACE(...)	::Royal::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define RL_CORE_INFO(...)	::Royal::Log::GetCoreLogger()->info(__VA_ARGS__)
#define RL_CORE_WARN(...)	::Royal::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define RL_CORE_ERROR(...)	::Royal::Log::GetCoreLogger()->error(__VA_ARGS__)
#define RL_CORE_FATAL(...)	::Royal::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client log macros
#define RL_TRACE(...)		::Royal::Log::GetClientLogger()->trace(__VA_ARGS__)
#define RL_INFO(...)		::Royal::Log::GetClientLogger()->info(__VA_ARGS__)
#define RL_WARN(...)		::Royal::Log::GetClientLogger()->warn(__VA_ARGS__)
#define RL_ERROR(...)		::Royal::Log::GetClientLogger()->error(__VA_ARGS__)
#define RL_FATAL(...)		::Royal::Log::GetClientLogger()->fatal(__VA_ARGS__)
