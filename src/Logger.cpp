#include "AuroraLog/Logger.h"
#include "AuroraLog/ConfigLoader.h"
#include "AuroraLog/LogEvent.h"

#include <memory>

namespace AuroraLog {
Logger::Logger() {}
Logger::Logger(LogConfig config): m_config(config) {}

void Logger::loadConfig(const std::string& configFilePath) {
    {
        std::unique_ptr<ConfigLoader> loader = std::make_unique<ConfigLoader>();
        LogConfig config = loader->load(configFilePath);
        m_config = config;
    }
}

Logger& Logger::getInstance() {
    static Logger instance;
    return instance;
}

void Logger::log(const LogEvent& event) {
    if (event.getLevel() <= m_config.level) {
        m_sink_manager.dispatch(event);
    }
}

void Logger::debug(const std::string& msg) { log(LogEvent(LogLevel::DEBUG, msg)); }

void Logger::info(const std::string& msg) { log(LogEvent(LogLevel::INFO, msg)); }

void Logger::warn(const std::string& msg) { log(LogEvent(LogLevel::WARN, msg)); }

void Logger::error(const std::string& msg) { log(LogEvent(LogLevel::ERROR, msg)); }

void Logger::fatal(const std::string& msg) { log(LogEvent(LogLevel::FATAL, msg)); }

void Logger::notifyListeners(const LogEvent::Ptr& event) {}
}  // namespace AuroraLog