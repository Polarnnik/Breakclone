cmake_minimum_required(VERSION 3.29)
project(Trye CXX)

set(CMAKE_CXX_STANDARD 20)

set(RAYLIB_LIB_PATH "${CMAKE_CURRENT_SOURCE_DIR}/lib/raylib/libraylib.so")


add_executable(Trye main.cpp
        window.cpp
        window.h
        app.cpp
        app.h
        States/main_screen.cpp
        States/main_screen.h
        States/state.h
)
target_include_directories(Trye PRIVATE include)
target_link_libraries(Trye PRIVATE ${RAYLIB_LIB_PATH})