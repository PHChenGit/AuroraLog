#ifndef AURORALOG_SINK_H
#define AURORALOG_SINK_H

#include <memory>
#include "AuroraLog/LogEvent.h"
#include "AuroraLog/LogFormatter.h"

namespace AuroraLog {
    class SinkManager {
    public:
        void addSink(LogSink::Ptr sink);
        void removeSink(LogSink::Ptr sink);
        void dispatch(const LogEvent& event);
    private:
        std::vector<std::shared_ptr<LogSink>> m_sinks;
    };

    class LogSink {
    public:
        using Ptr = std::shared_ptr<LogSink>;
        virtual ~LogSink() = default;

        virtual void log(const LogEvent& event) = 0;
        void setFormatter(std::unique_ptr<LogFormatter> formatter);
    protected:
        LogFormatter* getFormatter();
    private:
        std::unique_ptr<LogFormatter> m_formatter;
    };

    class ConsoleSink : public LogSink {
    public:
        void log(const LogEvent& event) override;
    };

    class FileSink : public LogSink {
    public:
        void log(const LogEvent& event) override;
    };
}
#endif //AURORALOG_SINK_H