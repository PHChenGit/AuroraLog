file(GLOB_RECURSE SOURCES "*.cpp")

add_library(AuroraLog SHARED ${SOURCES}
        ../examples/basic_usage/basic_usage.cpp
        ../examples/config_usage/config_usage.cpp
        ../include/AuroraLog/LogFormatter.h
        LogFormatter.cpp)

target_include_directories(AuroraLog
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../include>
        $<INSTALL_INTERFACE:include>
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)