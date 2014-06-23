# Project name
project(test)

# Minimum CMake version
cmake_minimum_required(VERSION 2.8)

# Add the modules
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")

# Find SFML
# If SFML can't be found, need to add the SFML_ROOT environment variable
find_package(SFML REQUIRED COMPONENTS graphics window system network)

# Include the directories needed
include_directories(src)
include_directories(include)
include_directories(${SFML_INCLUDE_DIR})

# Set some variables
set(SOURCE_FILES src/main.cpp src/test.cpp)
set(HEADER_FILES include/test.hpp)
set(EXECUTABLE_NAME ethereal-star)

# Add the executable
add_executable(${EXECUTABLE_NAME} ${SOURCE_FILES} ${HEADER_FILES})

# Link against SFML
target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
