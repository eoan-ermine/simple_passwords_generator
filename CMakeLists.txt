cmake_minimum_required(VERSION 3.5)

project (simple_passwords_generator)

set(SOURCES
    simple_passwords_generator/main.cpp
)

add_executable(simple_passwords_generator ${SOURCES})