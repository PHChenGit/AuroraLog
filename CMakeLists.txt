cmake_minimum_required(VERSION 3.25)
project(AuroraLog VERSION 1.0.0 LANGUAGES CXX)

# 當在 Build 目錄執行程式時，自動尋找連結的 Library
set(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE)
set(CMAKE_BUILD_RPATH_USE_ORIGIN TRUE)

# 讓執行檔紀錄 Library 的路徑 (Mac/Linux 需要)
if (APPLE)
    set(CMAKE_MACOSX_RPATH ON)
elseif (UNIX)
    # 這行最重要：把 library 的路徑寫進執行檔
    set(CMAKE_SKIP_BUILD_RPATH  FALSE)
endif()

include(FetchContent)
FetchContent_Declare(
    yaml-cpp
    GIT_REPOSITORY https://github.com/jbeder/yaml-cpp.git
    GIT_TAG        0.8.0
)
FetchContent_MakeAvailable(yaml-cpp)

# 設定 C++ 標準
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

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