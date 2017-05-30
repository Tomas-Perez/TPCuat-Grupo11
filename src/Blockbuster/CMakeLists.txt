set(blockbuster_SRCS main.c Client.c Client.h Admin.c Admin.h Rent.c Rent.h BlockbusterDatabase.c BlockbusterDatabase.h Movie.c Movie.h mainMenu.c BlackbusterInterface.c)
add_library(blockbuster ${blockbuster_SRCS})
add_executable(blockbusterEXE main.c)
target_link_libraries(blockbusterEXE blockbuster util structs)
