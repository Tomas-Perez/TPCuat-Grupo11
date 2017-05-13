set(BBTest_SRCS ../CUTest/CuTest.c BlockbusterTests.c)
add_executable(runBBTests ${BBTest_SRCS})
# target_link_libraries(runBBTests blockbuster)