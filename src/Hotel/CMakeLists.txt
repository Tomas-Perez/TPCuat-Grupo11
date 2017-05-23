set(hotel_SRCS HotelDatabase.c Room.c Reservation.c HotelInvoice.c HotelClient.c)
add_library(hotel ${hotel_SRCS})
add_executable(hotelEXE main.c)
target_link_libraries(hotelEXE hotel)