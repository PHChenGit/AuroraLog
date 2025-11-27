cmake_minimum_required(VERSION 3.25)
project(AuroraLog VERSION 1.0.0 LANGUAGES CXX)

# 設定 C++ 標準
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 支援資料夾分層 (IDE 顯示用)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# 加入子目錄
add_subdirectory(src)

# 只有在作為主專案編譯時，才開啟測試和範例
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    enable_testing()
#    add_subdirectory(tests)
    add_subdirectory(examples)
endif()