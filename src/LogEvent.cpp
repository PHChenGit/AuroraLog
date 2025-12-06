#include "AuroraLog/LogEvent.h"
#include <algorithm> // Required for std::transform
#include <cctype>    // Required for ::tolower

namespace AuroraLog {
    const char* LogLevelToString(LogLevel level) {
        switch (level) {
            case LogLevel::DEBUG:
                return "DEBUG";
            case LogLevel::INFO:
                return "INFO";
            case LogLevel::WARN:
                return "WARN";
            case LogLevel::ERROR:
                return "ERROR";
            case LogLevel::FATAL:
                return "FATAL";
            default:
                return "UNKNOWN";
        }
    }

    const LogLevel StringToLogLevel(std::string level) {
        std::transform(level.begin(), level.end(), level.begin(), ::tolower);
        if (level == "debug") {
            return LogLevel::DEBUG;
        } else if (level == "info") {
            return LogLevel::INFO;
        } else if (level == "warn") {
            return LogLevel::WARN;
        } else if (level == "error") {
            return LogLevel::ERROR;
        } else if (level == "fatal") {
            return LogLevel::FATAL;
        } else {
            return LogLevel::UNKNOWN;
        }
    }

    void LogEvent::setLevel(LogLevel level) {
        m_level = level;
    }

    void LogEvent::setFile() {
        
    }

    void LogEvent::setLine(uint32_t line_number) {

    }

    void LogEvent::setTime() {

    }

    void LogEvent::setThreadId(uint32_t thread_id) {
        
    }
}