#ifndef AURORALOG_LOGLEVEL_H
#define AURORALOG_LOGLEVEL_H
namespace AuroraLog {
    enum class LogLevel {
        UNKNOWN = 0,
        DEBUG,
        INFO,
        WARN,
        ERROR,
        FATAL
    };

    // 輔助函式：將 Level 轉為字串 (給 LogFormatter 用)
    const char* LogLevelToString(LogLevel level);
};
#endif //AURORALOG_LOGLEVEL_H