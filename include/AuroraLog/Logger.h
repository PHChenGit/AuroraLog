#ifndef AURORALOG_LOGGER_H
#define AURORALOG_LOGGER_H

#include <memory>
#include <string>
#include <vector>
#include <list>
#include "AuroraLog/LogEvent.h"
#include "AuroraLog/Sink.h"
#include "AuroraLog/LogLevel.h"

namespace AuroraLog {
    class Logger {
    public:
        using Ptr = std::shared_ptr<Logger>;

        Logger(const std::string& name = "root");

        void log(const LogEvent::Ptr& event);

        // 管理 Sinks (可以同時有多個輸出地)
        void addSink(const LogSink::Ptr& sink);
        void clearSinks();

        // 取得/設定 全域等級
        LogLevel getLevel() const { return m_level; }
        void setLevel(const LogLevel& level) { m_level = level; }

        const std::string& getName() const { return m_name; }

    private:
        std::string m_name;                      // Logger 名稱 (便於區分模組)
        LogLevel m_level = LogLevel::DEBUG;      // 低於此等級的 Log 直接忽略
        std::vector<LogSink::Ptr> m_sinks;       // 輸出目的地列表
    };

} // namespace Aurora

#endif //AURORALOG_LOGGER_H