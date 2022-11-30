cmake_minimum_required(VERSION 3.8)

project(StringNumTest)


set(This StringNumTest)

set(Source
    main.cpp
)

add_executable(${This} ${Source})
target_link_libraries(${This} PUBLIC
    gtest_main
    StringNum
)

add_test(
    NAME ${This}
    COMMAND ${This}
)