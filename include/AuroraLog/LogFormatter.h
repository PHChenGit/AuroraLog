#ifndef AURORALOG_LOGFORMATTER_H
#define AURORALOG_LOGFORMATTER_H

#include <memory>
#include <string>
#include <vector>
#include "AuroraLog/LogEvent.h"

namespace AuroraLog {
    class LogFormatter {
    public:
        using Ptr = std::shared_ptr<LogFormatter>;

        /**
         * @brief Constructor
         * @param pattern 格式模板，例如 "%d{%Y-%m-%d %H:%M:%S} [%p] %f:%l %m%n"
         */
        LogFormatter(const std::string& pattern);

        /**
         * Convert
         * @param event
         * @return
         */
        std::string format(LogEvent::Ptr event);

        void setMessage(const std::string& message);

    private:

    };
}

#endif //AURORALOG_LOGFORMATTER_H