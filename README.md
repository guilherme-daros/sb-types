# Antimony Types

The foundation utility library for the Antimony project. This library provides core C++23 patterns and types used across the entire ecosystem.

## Features
- **Result Handling:** `sb::Result<T>` based on `std::expected`.
- **Concurrency:** A lightweight, configurable `ThreadPool`.
- **Patterns:** CRTP-based `Singleton` implementation.
- **Metaprogramming Utilities:** 
  - `EnumStr`: Enum-to-string conversion.
  - `Typename`: Compile-time type name retrieval.
  - `StringLiteral`: Compile-time string literal wrapping for template parameters.

## Requirements
- C++23 compatible compiler (Clang 16+, GCC 13+).
- CMake 3.28+.

## Usage (CMake)
```cmake
add_subdirectory(extern/antimony-types)
target_link_libraries(YourTarget PRIVATE sb::types)
```
