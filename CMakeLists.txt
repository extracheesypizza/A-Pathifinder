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

set(SFML_STATIC_LIBRARIES TRUE)

target_include_directories(AstarPathfind PUBLIC src/SFML/include)

target_link_directories(AstarPathfind PRIVATE src/SFML/src)

FILE(GLOB_RECURSE LibFiles "src/*.hpp")
add_custom_target(headers SOURCES ${LibFiles})



target_link_libraries(AstarPathfind sfml-graphics)
# target_link_libraries(${EXECUTABLE_NAME} "${CMAKE_SOURCE_DIR}/src/SFML/extlibs/libs-osx/Frameworks/freetype.framework/Versions/A/freetype")
target_compile_features(AstarPathfind PRIVATE cxx_std_17)


