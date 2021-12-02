cmake_minimum_required(VERSION 3.16)

project(bomberman)

set(CMAKE_CXX_STANDARD 14)

find_package(raylib 3.0 QUIET)
include_directories(include)

if (NOT raylib_FOUND)
    include(FetchContent)

    FetchContent_Declare(
            raylib
            URL https://github.com/raysan5/raylib/archive/master.tar.gz
    )

    FetchContent_GetProperties(raylib)
    if (NOT raylib_POPULATED)
        set(FETCHCONTENT_QUIET NO)
        FetchContent_Populate(raylib)

        set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

        add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})

    endif()

endif()

if (UNIX)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})
endif()

set (SRC
        src/Button.cpp
        src/Core.cpp
        src/Platform.cpp
        src/Map.cpp
        src/Camera.cpp
        src/Player.cpp
        src/main.cpp
        src/collider.cpp
        src/Bombe.cpp)

add_executable(${PROJECT_NAME} ${SRC})

target_link_libraries(${PROJECT_NAME} raylib)
target_compile_definitions(bomberman PUBLIC ASSETS_PATH="${CMAKE_CURRENT_SOURCE_DIR}/pic/")
target_compile_definitions(bomberman PUBLIC SOUNDS_PATH="${CMAKE_CURRENT_SOURCE_DIR}/sounds/")