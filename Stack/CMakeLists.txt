cmake_minimum_required(VERSION 3.0.0)
project(Stack_proj VERSION 0.1.0)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES

    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp

    # ${CMAKE_CURRENT_SOURCE_DIR}/unitTestStack.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/lstack.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/rstack.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/stack.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/abstractStack.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/stack_tests.hpp
)

add_executable(Stack_proj ${SOURCES})

target_include_directories(Stack_proj PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)