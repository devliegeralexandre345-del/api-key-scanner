cmake_minimum_required(VERSION 3.16)
project(api_key_scanner LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)

include_directories(include)

# Exécutable principal
add_executable(api_key_scanner src/main.cpp src/scanner.cpp src/regex_patterns.cpp)

# Tests unitaires
enable_testing()
add_executable(unit_tests tests/test.cpp src/scanner.cpp src/regex_patterns.cpp)
add_test(NAME AllTests COMMAND unit_tests)