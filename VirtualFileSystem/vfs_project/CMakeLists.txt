cmake_minimum_required(VERSION 3.12)

project(VirtualFileSystem LANGUAGES CXX)

#
# C++ Standard
#
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#
# Compiler Warnings
#
add_compile_options(
    -Wall
    -Wextra
    -Wpedantic
)

#
# Include Directory
#
include_directories(${PROJECT_SOURCE_DIR}/include)

#
# Dependencies
#
find_package(Curses REQUIRED)
find_package(GTest REQUIRED)

#
# Core Library
# (all production code except main.cpp)
#
file(GLOB VFS_CORE_SOURCES
    "${PROJECT_SOURCE_DIR}/src/*.cpp"
)

add_library(
    vfs_core
    ${VFS_CORE_SOURCES}
)

target_link_libraries(
    vfs_core
    PUBLIC
    readline
    ${CURSES_LIBRARIES}
)

target_include_directories(
    vfs_core
    PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

#
# Main Application
#
add_executable(
    vfs
    main.cpp
)

target_link_libraries(
    vfs
    PRIVATE
    vfs_core
)

#
# Tests
#
file(GLOB TEST_SOURCES
    "${PROJECT_SOURCE_DIR}/tests/*.cpp"
)

add_executable(
    vfs_tests
    ${TEST_SOURCES}
)

target_link_libraries(
    vfs_tests
    PRIVATE
    vfs_core
    GTest::gtest
    GTest::gtest_main
)

#
# CTest Integration
#
enable_testing()

include(GoogleTest)

gtest_discover_tests(vfs_tests)