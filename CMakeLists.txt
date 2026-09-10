# Define CMake version —here we just use the same minimum as Crow
cmake_minimum_required(VERSION 3.15.0 FATAL_ERROR)

# Define the project name and language
project(demo LANGUAGES CXX)
add_executable(${PROJECT_NAME} src/main.cpp)

# Set required C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# Turn off nice-to-have features for simplicity
set(CROW_ENABLE_SSL OFF)
set(CROW_ENABLE_COMPRESSION OFF)

# Omit building Crow's examples and tests, and inform Crow about asio's location
set(CROW_BUILD_EXAMPLES OFF)
set(CROW_BUILD_TESTS OFF)
set(ASIO_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/external/asio/include)

target_include_directories(${PROJECT_NAME}
  PRIVATE
  ${PROJECT_SOURCE_DIR}/external/Crow/include
)

# Inform Cmake about Crow
add_subdirectory(external/Crow)

# Link our target with Crow
target_link_libraries(${PROJECT_NAME}
  PRIVATE
  Crow::Crow
)
