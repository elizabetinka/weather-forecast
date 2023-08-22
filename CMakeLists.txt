cmake_minimum_required(VERSION 3.23)
project(weather)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#link_directories(labwork-6-elizabetinka)
#add_subdirectory(labwork-6-elizabetinka)



add_executable(weather main.cpp Printer.h)
target_link_libraries(weather PRIVATE ITMLparse)
if (WIN32)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
endif()
include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
        GIT_TAG 32fd1453194c37d5136577ee55629b863a42333f) # The commit hash for 1.10.x. Replace with the latest from: https://github.com/libcpr/cpr/releases
FetchContent_MakeAvailable(cpr)
target_link_libraries(weather PRIVATE cpr::cpr)


include(FetchContent)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.2/json.tar.xz)
FetchContent_MakeAvailable(json)

target_link_libraries(weather PRIVATE nlohmann_json::nlohmann_json)


find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
target_link_libraries(weather PRIVATE ${CURSES_LIBRARIES})








# clang++ main.cpp -o main
