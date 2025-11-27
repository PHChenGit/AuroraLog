#ifndef AURORALOG_SINK_H
#define AURORALOG_SINK_H

#include <memory>
#include "AuroraLog/LogEvent.h"

namespace AuroraLog {
    class LogSink {
    public:
        using Ptr = std::shared_ptr<LogSink>;
        virtual ~LogSink() {}

        // Write log to file or console
        virtual void log(LogEvent::Ptr event) = 0;

        // 可選：設定該 Sink 的專屬 Level (例如 Console 只顯示 INFO, File 紀錄 DEBUG)
        void setLevel(LogLevel level) { m_level = level; }
        LogLevel getLevel() const { return m_level; }

    protected:
        LogLevel m_level = LogLevel::DEBUG;
    };

}
#endif //AURORALOG_SINK_H