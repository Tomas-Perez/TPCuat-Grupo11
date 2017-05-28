set(library_SRCS main.c Book.h Material.h Material.c Library.h Library.c Book.c Book.h Magazine.c Magazine.h Person.c Person.h Borrow.c Borrow.h Student.c Student.h Teacher.c Teacher.h MainMenu.c LibraryInterface.c)
add_library(library ${library_SRCS})
add_executable(libraryEXE main.c)
target_link_libraries(libraryEXE library util)