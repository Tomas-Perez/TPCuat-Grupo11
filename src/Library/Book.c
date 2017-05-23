#include <malloc.h>
#include <memory.h>
#include "Book.h"

Book* newBook(int idMaterial, char* editorial){
    Book* book = malloc(sizeof(Book));
    book->idMaterial = idMaterial;
    book->editorial = malloc(sizeof(char) * (strlen(editorial) + 1));
    strcpy(book->editorial, editorial);
    return book;
}
void destroyBook(Book* book){
    free(book->editorial);
    free(book);
}
