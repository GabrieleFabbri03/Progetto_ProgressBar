cmake_minimum_required(VERSION 4.0)
project(Progetto_ProgressBar)

set(CMAKE_CXX_STANDARD 20)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(Progetto_ProgressBar main.cpp
        Observer.h
        Observable.h
        ProgressBar.h
        ProgressBar.cpp)

target_link_libraries(Progetto_ProgressBar sfml-graphics sfml-window sfml-system)
