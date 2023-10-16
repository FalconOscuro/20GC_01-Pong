cmake_minimum_required(VERSION 3.12)

project(Pong
    VERSION 0.1.0
    LANGUAGES CXX
    DESCRIPTION "Pong made for the 20 game challenge using sdl2"
)

find_package(SDL2 REQUIRED)

if(NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
endif()

if(NOT CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 17 CACHE STRING "")
endif()

if (NOT MSVC)
    add_compile_options(-Wall -Wextra -Wpedantic)

    if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
        message(STATUS "Switching Clang to DWARF v4")
        add_compile_options(-gdwarf-4)
    endif()

    if(PROJECT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
        add_compile_options(-Werror)
    endif()
endif()

file(GLOB_RECURSE
    sources
    "${PROJECT_SOURCE_DIR}/src/*"    
)

include_directories(
    "${PROJECT_SOURCE_DIR}/include"
    "${SDL2_INCLUDE_DIRS}"
)

add_executable(${PROJECT_NAME} ${sources})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})