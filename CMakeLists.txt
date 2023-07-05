cmake_minimum_required(VERSION 3.24)
project(Graphico)

set(CMAKE_CXX_STANDARD 20)

add_executable(Graphico main.cpp
        buttons/gui.cpp buttons/gui.h
        buttons/tbuttons.cpp buttons/tbuttons.h
        buttons/textbox.cpp buttons/textbox.h
        resources/tcolors.h resources/tsample.h
        graphs/tvertex.cpp graphs/tgraph.h graphs/tgraph.cpp
        algo/algos.h algo/algos.cpp
        bs_threadpool/BS_thread_pool_light.hpp)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/cpp/sfml/SFML-2.5.1/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network)

include_directories(C:/cpp/sfml/SFML-2.5.1/include)
target_link_libraries(Graphico sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
