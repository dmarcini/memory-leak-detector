cmake_minimum_required(VERSION 3.10)

project(memory-leak-detector)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

include_directories(include)

set(SOURCES src/main.cpp
            src/memory_leak_detector.cpp
            src/memory_list.cpp
            src/override_new_operator.cpp
            src/override_delete_operator.cpp)

add_executable(memory-leak-detector ${SOURCES})
