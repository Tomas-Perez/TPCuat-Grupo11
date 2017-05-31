#include <malloc.h>
#include <memory.h>
#include "Book.h"

/*
 * Function: newBook
 * Description: Creates a new Book with the given data.
 * Returns: Book pointer.
 */
Book* newBook(int idMaterial, char* editorial){
    Book* book = malloc(sizeof(Book));
    book->idMaterial = idMaterial;
    book->editorial = malloc(sizeof(char) * (strlen(editorial) + 1));
    strcpy(book->editorial, editorial);
    return book;
}

/*
 * Function: destroyBook
 * Description: Deallocates all memory related to the Book.
 * Returns: --
 */
void destroyBook(Book* book){
    free(book->editorial);
    free(book);
}
