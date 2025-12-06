#ifndef AURORALOG_CONFIGLOADER_H_
#define AURORALOG_CONFIGLOADER_H_

#include <vector>
#include <memory>
#include <string>
#include <unordered_map>

#include "AuroraLog/LogEvent.h"

namespace AuroraLog {
struct LogConfig {
    /**
     * Minimuml logging level
     */
    LogLevel level = LogLevel::INFO;
    
    std::vector<std::string> sinks {"console"};
    
    std::string file_path;
    
    /**
     * Logging format, json or plain-text
     */
    std::string format_type;
    int max_file_size;
    int max_file_count;
};

class IConfigParser {
public:
    using Ptr = std::unique_ptr<IConfigParser>;
    virtual ~IConfigParser() = default;
    virtual LogConfig parse(const std::string& configPath) = 0;
};

class YamlConfigParser : public IConfigParser {
public:
    LogConfig parse(const std::string& configPath) override;
};

class JsonConfigParser : public IConfigParser {
public:
    LogConfig parse(const std::string& configPath) override;
};

class ConfigLoader {
public:
    static LogConfig load(const std::string& configPath);

private:
    // 工廠方法：根據副檔名建立 Parser
    static std::unique_ptr<IConfigParser> createParser(const std::string& extension);
};
}  // namespace AuroraLog
#endif