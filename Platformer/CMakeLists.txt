cmake_minimum_required(VERSION 3.24)
project(Platformer)

set(CMAKE_CXX_STANDARD 17)

add_executable(Platformer main.cpp Player.cpp Player.h PreCompiledHeaders.h PreCompiledHeaders.cpp Game.cpp Game.h Environment.h Environment.cpp Map.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(c:/SFML/include)
target_link_libraries(Platformer sfml-system sfml-window sfml-graphics sfml-audio)