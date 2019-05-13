cmake_minimum_required(VERSION 2.8)

project(space-invaders)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/findcmake" ${CMAKE_MODULE_PATH})

find_package(SFML 2.4 REQUIRED COMPONENTS system window graphics audio)

include_directories(
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_BINARY_DIR}/src
    )
add_subdirectory(src)
