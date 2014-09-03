# Project name
project(ethereal-star)

# Minimum CMake version
cmake_minimum_required(VERSION 2.8)

# Add the modules
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")

# Using C++11
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# Find SFML
# If SFML can't be found, need to add the SFML_ROOT environment variable
find_package(SFML 2 REQUIRED COMPONENTS graphics window system network)

# Include the directories needed
include_directories(src)
include_directories(include)
include_directories(${SFML_INCLUDE_DIR})

# Set some variables
set(SOURCE_FILES src/main.cpp src/Game.cpp src/Gui.cpp src/Entity.cpp src/TextureManager.cpp src/Tile.cpp src/Map.cpp src/Player.cpp)
set(HEADER_FILES include/Game.hpp include/Gui.hpp include/Entity.hpp include/TextureManager.hpp include/Tile.hpp include/Map.hpp include/Player.hpp)
set(EXECUTABLE_NAME ethereal-star)

# Add the executable
add_executable(${EXECUTABLE_NAME} ${SOURCE_FILES} ${HEADER_FILES})

# Link against SFML
target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
