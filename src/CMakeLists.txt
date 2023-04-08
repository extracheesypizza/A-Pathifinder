cmake_minimum_required(VERSION 3.5)

project(AstarPathfind LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(BUILD_SHARED_LIBS FALSE)

add_executable(AstarPathfind main.cpp)

set(SFML_DIR "SFML/lib/cmake/SFML")
target_link_libraries(AstarPathfind sfml-graphics)

FILE(COPY ../res/arial.ttf DESTINATION "${CMAKE_BINARY_DIR}")

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML 2.5.1 REQUIRED graphics window system)


