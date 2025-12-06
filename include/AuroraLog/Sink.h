#ifndef AURORALOG_SINK_H
#define AURORALOG_SINK_H

#include <memory>
#include "AuroraLog/LogEvent.h"
#include "AuroraLog/LogFormatter.h"

namespace AuroraLog {

    class LogSink {
    public:
        using Ptr = std::shared_ptr<LogSink>;
        virtual ~LogSink() = default;

        virtual void log(LogEvent::Ptr event) = 0;
        void setFormatter(std::unique_ptr<LogFormatter> formatter);
    protected:
        LogFormatter* getFormatter();
    private:
        std::unique_ptr<LogFormatter> m_formatter;
    };

    class ConsoleSink : public LogSink {
    public:
        void log(LogEvent::Ptr event) override;
    };

    class FileSink : public LogSink {
    public:
        void log(LogEvent::Ptr event) override;
    };

    class SinkManager {
    public:
        void addSink(LogSink::Ptr sink);
        void removeSink(LogSink::Ptr sink);
        void dispatch(LogEvent::Ptr event);
    private:
        std::vector<std::shared_ptr<LogSink>> m_sinks;
    };
}
#endif //AURORALOG_SINK_H