cmake_minimum_required(VERSION 3.0.0)
project(List_proj VERSION 0.1.0)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES

    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/llist.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/abstractList.hpp
)

add_executable(List_proj ${SOURCES})

target_include_directories(List_proj PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)