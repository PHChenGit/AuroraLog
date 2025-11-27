#ifndef AURORALOG_CONSOLESINK_H
#define AURORALOG_CONSOLESINK_H

#include "AuroraLog/Sink.h"
#include "AuroraLog/LogEvent.h"

namespace AuroraLog {

    class ConsoleSink : public LogSink {
    public:
        // 實作父類的純虛擬函式
        void log(LogEvent::Ptr event) override;
    };

} // namespace Aurora
#endif //AURORALOG_CONSOLESINK_H