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
    src/operators/Minus.cpp
)

add_library(${This} STATIC ${Sources} ${Headers})

add_subdirectory(test)


# add_executable(StringNum)

# set(SRC ./src)
# set(INCLUDE ./include)

# enable_testing()
# add_subdirectory(googletest)
# add_subdirectory(test)

# target_sources(StringNum PUBLIC
#     ${SRC}/main.cpp
#     ${SRC}/StringNum.cpp
#     ${SRC}/operators/BooleanOperators.cpp
#     ${SRC}/operators/Plus.cpp
#     ${SRC}/operators/Minus.cpp
# )

# target_include_directories(StringNum PUBLIC
#     ${INCLUDE}/
# )

# target_compile_options(StringNum PUBLIC
#     $<$<CXX_COMPILER_ID:MSVC>:/W3 /MD -D_WIN32_WINNT=0x0A00 /D_ITERATOR_DEBUG_LEVEL=0 /permissive- /std:c++17>
#     $<$<OR:$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:Clang>>: -Wall -Werror -fPIC -ldl -O3 -g>
# )