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
}