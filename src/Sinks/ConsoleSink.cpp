#include <iostream>
#include "AuroraLog/Sink.h"

namespace AuroraLog {
    void ConsoleSink::log(const LogEvent& event) {
        if (auto fmt = getFormatter()) {
            std::cout << fmt->format(event); 
        }
    }
}
