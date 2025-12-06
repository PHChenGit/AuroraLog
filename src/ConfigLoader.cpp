#include "AuroraLog/ConfigLoader.h"
#include "AuroraLog/LogEvent.h"

#include <yaml-cpp/yaml.h>

#include <filesystem>
#include <vector>

namespace AuroraLog {
LogConfig YamlConfigParser::parse(const std::string& configPath) {
    YAML::Node config = YAML::LoadFile(configPath);
    std::string minLevel = config["min_level"].as<std::string>();
    std::vector<std::string> sinks = config["sinks"].as<std::vector<std::string>>();
    std::string format = config["format"].as<std::string>();
    std::string timestampFormat = config["timestamp_format"].as<std::string>();
    LogLevel logLevel = StringToLogLevel(minLevel);
    
    LogConfig logConfig;
    logConfig.level = logLevel;
    logConfig.format_type = format;
    logConfig.
};

LogConfig JsonConfigParser::parse(const std::string& configPath) {};

LogConfig ConfigLoader::load(const std::string& configPath) {
    std::filesystem::path p1(configPath);
    IConfigParser parser = createParser(p1.extension());
    LogConfig config = parser.parse();
}

std::unique_ptr<IConfigParser> ConfigLoader::createParser(const std::string& extension) {
    switch (extension) {
        case 'yaml':
            YamlConfigParser ymlParser = new YamlConfigParser();
            return ymlParser;
            break;

        case 'json':
            JsonConfigParser jsonParser = new JsonConfigParser();
            return jsonParser;
            break;

        default:
            break;
    }
}
};  // namespace AuroraLog