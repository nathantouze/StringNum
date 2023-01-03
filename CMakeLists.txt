cmake_minimum_required(VERSION 3.8)


set(This StringNum)
project(${This} C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()
add_subdirectory(googletest)

set(HeaderDir ${PROJECT_SOURCE_DIR}/include)

set(Headers
    ${HeaderDir}/StringNum.hpp
)

set(SourceDir ${PROJECT_SOURCE_DIR}/src)
set(Sources
    src/StringNum.cpp
    src/operators/BooleanOperators.cpp
    src/operators/Plus.cpp
    src/operators/PlusPlus.cpp
    src/operators/Minus.cpp
    src/operators/Multiply.cpp
    src/operators/Divide.cpp 
    src/operators/Modulo.cpp
)

add_library(${This} STATIC ${Sources} ${Headers})

add_subdirectory(test)