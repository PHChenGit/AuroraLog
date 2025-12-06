#include "AuroraLog/Sink.h"

namespace AuroraLog {
    void SinkManager::addSink(LogSink::Ptr sink) {
        m_sinks.push_back(sink);
    }

    void SinkManager::removeSink(LogSink::Ptr sink) {
        return ;
    }

    void SinkManager::dispatch(const LogEvent& event) {
        for (const auto& sink : m_sinks) {
            sink->log(event);
        }
    }

    void LogSink::setFormatter(std::unique_ptr<LogFormatter> formatter) {
        m_formatter = std::move(formatter);
    }

    LogFormatter* LogSink::getFormatter() {
        return m_formatter.get();
    }
}