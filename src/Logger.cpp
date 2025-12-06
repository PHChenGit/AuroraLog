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

void Logger::applyConfig(const LogConfig& config) {
    m_config = config;
}

Logger& Logger::getInstance() {
    static Logger instance;
    return instance;
}

void Logger::log(LogEvent::Ptr event) {
    if (event->getLevel() <= m_config.level) {
        m_sink_manager.dispatch(event);
    }
}

void Logger::debug(const std::string& msg) { 
    LogEvent::Ptr event = std::make_shared<LogEvent>(LogLevel::DEBUG, msg);
    log(std::move(event));
}

void Logger::info(const std::string& msg) { 
    LogEvent::Ptr event = std::make_shared<LogEvent>(LogLevel::INFO, msg);
    log(std::move(event));
}

void Logger::warn(const std::string& msg) { 
    LogEvent::Ptr event = std::make_shared<LogEvent>(LogLevel::WARN, msg);
    log(std::move(event));
}

void Logger::error(const std::string& msg) { 
    LogEvent::Ptr event = std::make_shared<LogEvent>(LogLevel::ERROR, msg);
    log(std::move(event));
}

void Logger::fatal(const std::string& msg) { 
    LogEvent::Ptr event = std::make_shared<LogEvent>(LogLevel::FATAL, msg);
    log(std::move(event));
}

void Logger::notifyListeners(const LogEvent::Ptr& event) {}
}  // namespace AuroraLog