#include "Log.h"

#include "spdlog/sinks/stdout_color_sinks.h"

namespace GLCore
{
	void Log::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		std::shared_ptr<spdlog::logger>& s_Logger = GetLogger();
		s_Logger = spdlog::stdout_color_mt("GLCore");
		s_Logger->set_level(spdlog::level::trace);

	}
}
