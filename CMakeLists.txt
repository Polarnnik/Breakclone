cmake_minimum_required(VERSION 3.29)
project(Breakclone CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")

find_package(raylib REQUIRED)

if (raylib_FOUND)
    message(STATUS "Found raylib: ${raylib_INCLUDE_DIRS}")
else()
    message(FATAL_ERROR "raylib not found")
endif()

include_directories(${raylib_INCLUDE_DIRS})

add_executable(Breakclone main.cpp
        window.cpp
        window.h
        app.cpp
        app.h
        States/main_screen.cpp
        States/main_screen.h
        States/state.h
        States/play_state.cpp
        States/play_state.h
)
target_link_libraries(Breakclone PRIVATE ${raylib_LIBRARIES})