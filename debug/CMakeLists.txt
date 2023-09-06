
cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)

project(debug VERSION 0.1 LANGUAGES CXX)

add_executable(debug "")

target_include_directories(debug
    PUBLIC
       $(CMAKE_CURRENT_LIST_DIR)/..
)

target_sources(debug
    PRIVATE
        $(CMAKE_CURRENT_LIST_DIR)/main.cpp
)
