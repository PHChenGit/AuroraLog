#include "AuroraLog/Logger.h"
#include "AuroraLog/Sink.h"
#include "AuroraLog/LogEvent.h"
#include <memory>
#include <string>

int main() {
    auto logger = std::make_shared<AuroraLog::Logger>();

    logger->info("Hello Aurora Log!");

    return 0;
}