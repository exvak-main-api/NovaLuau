# NovaLuau

NovaLuau is a Luau-style runtime written in C++ with a Python interface.

## Features

- C++ core runtime
- Python bindings
- Environment system
- Value system
- Tables
- Functions
- Parser
- Debug library
- Base library

## Structure

NovaLuau/ │ ├── core/ ├── parser/ ├── objects/ ├── libraries/ ├── bindings/ ├── python/ └── CMakeLists.txt

## Build

Requirements:

- C++17 compiler
- CMake
- Python development headers


Build:

```bash
mkdir build
cd build

cmake ..
cmake --build .

Python usage

import novaluau

novaluau.create()

novaluau.execute("""
local value = 10
print(value)
""")

```

Goals
NovaLuau aims to provide:
Luau syntax support
Runtime execution
Tables
Functions
Debug information
Python integration
