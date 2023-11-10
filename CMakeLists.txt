cmake_minimum_required(VERSION 3.5)

project (simple_passwords_generator)

set(CMAKE_CXX_STANDARD 20)
set(SOURCES
    simple_passwords_generator/main.cpp
)

add_executable(simple_passwords_generator ${SOURCES})