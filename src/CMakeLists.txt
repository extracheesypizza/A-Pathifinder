cmake_minimum_required(VERSION 3.5)

project(AstarPathfind LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(AstarPathfind main.cpp Application.cpp Astar.cpp Grid.cpp Node.cpp Viewer.cpp)

FILE(GLOB_RECURSE LibFiles "*.hpp")
add_custom_target(headers SOURCES ${LibFiles})

target_link_libraries(AstarPathfind sfml-graphics)

include_directories(${CMAKE_CURRENT_LIST_DIR}/SFML/include)
target_link_libraries(AstarPathfind ${CMAKE_CURRENT_LIST_DIR}/SFML/lib)

find_package(SFML REQUIRED graphics network audio window system)


