cmake_minimum_required(VERSION 4.0)
project(Progetto_ProgressBar)

set(CMAKE_CXX_STANDARD 20)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)
find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})


add_executable(Progetto_ProgressBar
        main.cpp
        Observer.h
        Observable.h
        ProgressBar.h
        ProgressBar.cpp
        FileLoader.h
        FileLoader.cpp
)
add_executable(Tests
        Test/Test.cpp
        Observer.h
        Observable.h
        ProgressBar.h
        ProgressBar.cpp
        FileLoader.h
        FileLoader.cpp
)

target_link_libraries(Progetto_ProgressBar sfml-graphics sfml-window sfml-system)
target_link_libraries(Tests
        GTest::GTest
        GTest::Main
        pthread
)

enable_testing()
add_test(NAME AllTests COMMAND Tests)