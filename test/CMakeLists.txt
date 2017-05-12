cmake_minimum_required(VERSION 3.3)
set(test_SRCS CUTest/CuTest.c AllTests.c)
add_executable(runUnitTests ${test_SRCS})
# target_link_libraries(runUnitTests core)