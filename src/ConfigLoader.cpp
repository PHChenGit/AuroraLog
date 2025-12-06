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
    
    return logConfig;
};

LogConfig JsonConfigParser::parse(const std::string& configPath) {
    throw std::runtime_error("JsonConfigParser is not implemented yet.");
};

LogConfig ConfigLoader::load(const std::string& configPath) {
    std::filesystem::path p1(configPath);
    auto parser = createParser(p1.extension().string());
    LogConfig config = parser->parse(configPath);
    return config;
}

std::unique_ptr<IConfigParser> ConfigLoader::createParser(const std::string& extension) {
    if (extension == ".yaml" || extension == ".yml") {
        return std::make_unique<YamlConfigParser>();
    } else if (extension == ".json") {
        return std::make_unique<JsonConfigParser>();
    } else {
        throw std::runtime_error("Unsupported config file format: " + extension);
    }
}
};  // namespace AuroraLog