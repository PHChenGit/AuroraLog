#include <iostream>
#include "AuroraLog/Sinks/ConsoleSink.h"

namespace AuroraLog {
    void ConsoleSink::log(LogEvent::Ptr event) {
        if (event->getLevel() < m_level) {
            return;
        }

        std::cout << "[" << event->getTime() << "] "
              << event->getContent()
              << std::endl;
    }
}
