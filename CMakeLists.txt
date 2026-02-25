cmake_minimum_required(VERSION 3.28)
project(antimony-types VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 1. Define the library and its sources
add_library(antimony-types STATIC 
    src/ThreadPool.cpp
    include/types/EnumStr.hpp
    include/types/Exception.hpp
    include/types/Result.hpp
    include/types/Singleton.hpp
    include/types/StringLiteral.hpp
    include/types/ThreadPool.hpp
    include/types/Typename.hpp
)

# 2. Configure Include Directories
target_include_directories(antimony-types PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# 3. Mandate C++23 for all consumers
target_compile_features(antimony-types PUBLIC cxx_std_23)

# 4. Create an alias (sb::types) for consistent namespacing
add_library(sb::types ALIAS antimony-types)

# Examples
option(BUILD_EXAMPLES "Build examples" ON)
if(BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()
