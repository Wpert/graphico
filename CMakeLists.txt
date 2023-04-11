cmake_minimum_required(VERSION 3.24)
project(Graphico)

set(CMAKE_CXX_STANDARD 20)

add_executable(Graphico main.cpp buttons/tbuttons.cpp buttons/tbuttons.h resources/tcolors.h graphs/tvertex.cpp graphs/tgraph.h graphs/tgraph.cpp resources/tsample.h buttons/gui.cpp buttons/gui.h algo/algos.h algo/algos.cpp buttons/textbox.cpp buttons/textbox.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/sfml_clion/SFML32/lib/cmake/SFML)
find_package(SFML COMPONENTS graphics window system  REQUIRED)

include_directories(C:/sfml_clion/SFML32/include)
target_link_libraries(Graphico sfml-graphics sfml-window sfml-system)