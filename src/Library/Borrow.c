#include <malloc.h>
#include <memory.h>
#include "Borrow.h"

/*
 * Function: newBorrow
 * Description: Creates a new Borrow with the given data.
 * Returns: Borrow pointer.
 */
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

/*
 * Function: destroyBorrow
 * Description: Deallocates all memory related to the Borrow.
 * Returns: --
 */
void destroyBorrow(Borrow* borrow){
    free(borrow->startDate);
    free(borrow->finishDate);
    free(borrow);
}
