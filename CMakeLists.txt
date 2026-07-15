cmake_minimum_required(VERSION 3.15)

project(NovaLuau)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


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
    core/Executor.cpp

    objects/Table.cpp
    objects/Function.cpp

    parser/Lexer.cpp
    parser/Parser.cpp

    libraries/Base.cpp
    libraries/Debug.cpp
)



add_executable(
    NovaLuauConsole

    main.cpp
)


target_link_libraries(
    NovaLuauConsole

    NovaLuau
)
