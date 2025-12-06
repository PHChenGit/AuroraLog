#include <iostream>

#include "AuroraLog/ConfigLoader.h"
#include "AuroraLog/Logger.h"

using namespace AuroraLog;

int main() {
    // 1. 取得 Logger 實體 (Singleton)
    // 此時 Logger 處於預設狀態 (例如: 只輸出到 Console, Level=INFO)
    Logger& logger = Logger::getInstance();

    logger.info("Application starting... (Default Config)");

    // 2. [核心流程] 載入設定
    // ConfigLoader 只負責產出資料 (LogConfig Struct)，完全不介入 Logger 的運作
    try {
        // Step A: ConfigLoader 讀取檔案 -> 產出 LogConfig 物件
        // 這裡會自動根據副檔名 (.yaml) 選擇 YamlParser
        LogConfig config = ConfigLoader::load("config.yaml");

        // Step B: Logger 接收 LogConfig 並依此初始化
        logger.applyConfig(config);

        logger.info("Configuration loaded successfully.");
    } catch (const std::exception& e) {
        // 錯誤處理：如果設定檔爛掉，Logger 依然可以使用預設值運作，不會讓程式 Crash
        logger.error(std::string("Failed to load config: ") + e.what());
        logger.warn("Using default configuration instead.");
    }

    return 0;
}