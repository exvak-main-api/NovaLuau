cmake_minimum_required(VERSION 3.15)

project(NovaLuau)


set(CMAKE_CXX_STANDARD 17)


include_directories(
    core
    parser
    objects
    libraries
)


add_library(
    NovaLuau
    SHARED

    core/Value.cpp
    core/Environment.cpp
    core/VM.cpp

    objects/Table.cpp
    objects/Function.cpp

    parser/Lexer.cpp
    parser/Parser.cpp

    libraries/Base.cpp
    libraries/Debug.cpp
)


find_package(Python3 COMPONENTS Development REQUIRED)


add_library(
    novaluau
    MODULE

    bindings/python.cpp
)


target_link_libraries(
    novaluau

    NovaLuau

    Python3::Python
)


set_target_properties(
    novaluau

    PROPERTIES

    PREFIX ""
)
