#pragma once

#include <memory>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

class Log {
public:
	static void initialize();

	static std::shared_ptr<spdlog::logger> getLogger() { return mtLogger; };
private:
	static std::shared_ptr<spdlog::logger> mtLogger;
};

#define LOG_CRITICAL(x) ::Log::getLogger()->critical(x)
#define LOG_ERROR(x) ::Log::getLogger()->error(x)
#define LOG_WARN(x) ::Log::getLogger()->warn(x)
#define LOG_INFO(x) ::Log::getLogger()->info(x)
#define LOG_DEBUG(x) ::Log::getLogger()->debug(x)
#define LOG_TRACE(x) ::Log::getLogger()->trace(x)