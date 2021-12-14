#include "Log.h"

std::shared_ptr<spdlog::logger> Log::mtLogger;

void Log::initialize() {
	auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
	console_sink->set_pattern("[Launcher] [%^%l%$] %v");
#ifdef APP_DEBUG
	console_sink->set_level(spdlog::level::trace);
#elif APP_NDEBUG
	console_sink->set_level(spdlog::level::warn);
#endif 

	Log::mtLogger = std::make_shared<spdlog::logger>("Launcher", console_sink);
	Log::mtLogger->set_level(spdlog::level::trace);
}