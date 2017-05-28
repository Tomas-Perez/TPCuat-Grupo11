#include <malloc.h>
#include <memory.h>
#include "Borrow.h"

Borrow* newBorrow(int idBorrow,int idMaterial,int idPerson, char* startDate, char* finishDate){
    Borrow* borrow = malloc(sizeof(Borrow));
    borrow->idBorrow = idBorrow;
    borrow->idMaterial = idMaterial;
    borrow->idPerson = idPerson;
    borrow->startDate = malloc(sizeof(char) * (strlen(startDate) + 1));
    strcpy(borrow->startDate, startDate);
    borrow->finishDate = malloc(sizeof(char) * (strlen(finishDate) + 1));
    strcpy(borrow->finishDate, finishDate);
    return borrow;
}
void destroyBorrow(Borrow* borrow){
    free(borrow->startDate);
    free(borrow->finishDate);
    free(borrow);
}
