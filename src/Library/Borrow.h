#ifndef TPCUAT_GRUPO11_BORROW_H
#define TPCUAT_GRUPO11_BORROW_H

typedef struct Borrow Borrow;
struct Borrow{
    int idBorrow;
    int idMaterial;
    int idPerson;
    char* startDate;
    char* finishDate;
};

Borrow* newBorrow(int idBorrow,int idMaterial,int idPerson, char* startDate, char* finishDate);
void destroyBorrow(Borrow* borrow);

#endif //TPCUAT_GRUPO11_BORROW_H
