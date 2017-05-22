#ifndef TPCUAT_GRUPO11_BOOK_H
#define TPCUAT_GRUPO11_BOOK_H

typedef struct Book Book;
struct Book{
    int idMaterial;
    char* editorial;
};
Book* newBook(int idMaterial, char* editorial);
void destroyBook(Book* book);

#endif //TPCUAT_GRUPO11_BOOK_H
