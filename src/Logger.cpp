//
// Created by 陳柏勳 on 2025/11/27.
//

#include "AuroraLog/Logger.h"

namespace AuroraLog {
    Logger::Logger(const std::string& name)
        : m_name(name), m_level(LogLevel::DEBUG) {}

    void Logger::addSink(const LogSink::Ptr& sink) {
        m_sinks.push_back(sink);
    }

    void Logger::clearSinks() {
        m_sinks.clear();
    }

    void Logger::log(const LogEvent::Ptr& event) {
        if (event->getLevel() < m_level) {
            return;
        }

        for (const auto& sink : m_sinks) {
            sink->log(event);
        }
    }

}