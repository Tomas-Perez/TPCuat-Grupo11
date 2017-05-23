set(hotel_SRCS main.c)
add_library(hotel ${hotel_SRCS})
add_executable(hotelEXE main.c)
target_link_libraries(hotelEXE hotel)