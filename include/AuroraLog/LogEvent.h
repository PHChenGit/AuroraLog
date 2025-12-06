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

    const LogLevel StringToLogLevel(const std::string& level);

    class LogEvent {
    public:
        using Ptr = std::shared_ptr<LogEvent>;
        LogEvent(LogLevel level, const char* file, uint32_t line, uint32_t threadId, uint32_t fiberId, uint64_t timestamp, const std::string& msg):
         m_level(level), m_file(file), m_line(line), m_threadId(threadId), m_fiberId(fiberId), m_time(timestamp), m_msg(msg) {};
    
        LogEvent(LogLevel level, const std::string& msg): m_level(level), m_msg(msg) {}
        
        void setLevel(LogLevel level);
        void setFile();
        void setLine(uint32_t line_number);
        void setTime();
        void setThreadId(uint32_t thread_id);
        
        LogLevel getLevel() const { return m_level; }
        const std::string& getMessage() const { return m_msg; }
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
        const std::string m_msg;// 外部傳入的 Log 訊息
    };
};

#endif //AURORALOG_LOGEVENT_H