cmake_minimum_required(VERSION 3.15)
project(text_analyzer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB CPP_SRC 
    "src/main.cc"
    "src/text_analyzer/*.cc"
    "src/file_system_utils/*.cc"
    "src/file_analyzer/*.cc"
    "src/directory_analyzer/*.cc"
)

include_directories(
    "src/text_analyzer"
    "src/file_system_utils"
    "src/file_analyzer"
    "src/directory_analyzer"
    "src/config"
)

add_executable(${PROJECT_NAME} ${CPP_SRC})

# =============== TESTS ===============

include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.14.0
)

FetchContent_MakeAvailable(googletest)

enable_testing()

file(GLOB TESTS_SRC
    "tests/tests.cc"
    "src/text_analyzer/*.cc"
)

add_executable(tests ${TESTS_SRC})

target_link_libraries(tests gtest gtest_main)

add_test(NAME TextAnalyzerTests COMMAND tests)
