set(HotelTest_SRCS ../CUTest/CuTest.c HotelTests.c HotelDatabaseTest.c)
add_executable(runHotelTests ${HotelTest_SRCS})
target_link_libraries(runHotelTests hotel)