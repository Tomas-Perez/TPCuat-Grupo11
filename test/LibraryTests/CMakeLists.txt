set(LibraryTest_SRCS ../CUTest/CuTest.c LibraryTests.c)
add_executable(runLibraryTests ${LibraryTest_SRCS})
# target_link_libraries(runLibraryTests library)