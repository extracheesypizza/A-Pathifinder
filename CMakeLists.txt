cmake_minimum_required(VERSION 3.5)

project(AstarPathfind LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src/SFML)

add_executable(AstarPathfind 
                                src/main.cpp 
                                src/Application.cpp 
                                src/Astar.cpp 
                                src/Grid.cpp 
                                src/Node.cpp 
                                src/Viewer.cpp)

FILE(COPY res/arial.ttf DESTINATION "${CMAKE_BINARY_DIR}")

target_include_directories(AstarPathfind PUBLIC src/SFML/include)

target_link_directories(AstarPathfind PRIVATE src/SFML/src)

target_link_libraries(AstarPathfind sfml-graphics)



