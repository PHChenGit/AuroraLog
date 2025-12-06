#include "AuroraLog/Logger.h"
#include "AuroraLog/Sinks/ConsoleSink.h"
#include "AuroraLog/LogLevel.h"
#include <memory>
#include <string>

int main() {
    auto logger = std::make_shared<AuroraLog::Logger>("MainLogger");

    auto consoleSink = std::make_shared<AuroraLog::ConsoleSink>();
    logger->addSink(consoleSink);

    AuroraLog::LogEvent::Ptr event(new AuroraLog::LogEvent(
        AuroraLog::LogLevel::INFO,
        __FILE__, __LINE__, 0, 0, 123456789,
        "Hello Aurora Log!"
    ));

    logger->log(event);

    return 0;
}