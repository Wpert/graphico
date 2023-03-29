cmake_minimum_required(VERSION 3.24)
project(Graphico)

set(CMAKE_CXX_STANDARD 17)

add_executable(Graphico main.cpp textbox.h dhilufdhufhh.cpp)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/sfml_clion/SFML32/lib/cmake/SFML)
find_package(SFML COMPONENTS graphics window system  REQUIRED)

include_directories(C:/sfml_clion/SFML32/include)
target_link_libraries(Graphico sfml-graphics sfml-window sfml-system )