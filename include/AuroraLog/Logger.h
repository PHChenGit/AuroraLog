#ifndef AURORALOG_LOGGER_H
#define AURORALOG_LOGGER_H

#include <list>
#include <memory>
#include <mutex>
#include <string>
#include <vector>

#include "AuroraLog/LogEvent.h"
#include "AuroraLog/Sink.h"
#include "AuroraLog/ConfigLoader.h"

namespace AuroraLog {
class Logger {
public:
    using Ptr = std::shared_ptr<Logger>;

    Logger();
    Logger(LogConfig config);

    void loadConfig(const std::string& configFilePath);
    static Logger& getInstance();

    void log(const LogEvent& event);
    void debug(const std::string& msg);
    void info(const std::string& msg);
    void warn(const std::string& msg);
    void error(const std::string& msg);
    void fatal(const std::string& msg);

private:
    std::mutex m_logger_mutex;
    LogConfig m_config;
    SinkManager m_sink_manager;

    void notifyListeners(const LogEvent::Ptr& event);
};

}  // namespace AuroraLog

#endif  // AURORALOG_LOGGER_H