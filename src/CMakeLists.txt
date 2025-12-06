file(GLOB_RECURSE SOURCES "*.cpp")

add_library(AuroraLog SHARED ${SOURCES})

target_include_directories(AuroraLog
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../include>
        $<INSTALL_INTERFACE:include>
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
)
target_link_libraries(AuroraLog PUBLIC yaml-cpp::yaml-cpp)