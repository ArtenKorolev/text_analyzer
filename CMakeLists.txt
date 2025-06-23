cmake_minimum_required(VERSION 3.15)
project(text_analyzer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB CPP_SRC 
    "src/main.cc"
    "src/text_analyzer/*.cc"
    "src/file_system_utils/*.cc"
)

include_directories(
    "src/text_analyzer"
    "src/file_system_utils"
)

add_executable(${PROJECT_NAME} ${CPP_SRC})