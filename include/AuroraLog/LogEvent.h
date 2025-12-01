#ifndef AURORALOG_LOGEVENT_H
#define AURORALOG_LOGEVENT_H

#include <string>
#include <memory>

namespace AuroraLog {
    class Logger;

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

    class LogEvent {
    public:
        using Ptr = std::shared_ptr<LogEvent>;

        LogEvent(LogLevel level, const char* file, uint32_t line, uint32_t threadId, uint32_t fiberId, uint64_t timestamp, const char* content):
         m_level(level), m_file(file), m_line(line), m_threadId(threadId), m_fiberId(fiberId), m_time(timestamp), m_content(content) {};

        LogLevel getLevel() const { return m_level; }
        const std::string& getContent() const { return m_content; }
        const char* getFile() const { return m_file; }
        uint32_t getLine() const { return m_line; }
        uint64_t getTime() const { return m_time; }
        uint32_t getThreadId() const { return m_threadId; }

    private:
        LogLevel m_level;
        const char* m_file;   // 檔名 (__FILE__)
        uint32_t m_line;       // 行號 (__LINE__)
        uint32_t m_threadId;  // 執行緒 ID
        uint32_t m_fiberId;   // 協程 ID (可選，針對高併發場景)
        uint64_t m_time;      // 時間戳
        std::string m_content;// 格式化後的 Log 訊息
    };
};

#endif //AURORALOG_LOGEVENT_H