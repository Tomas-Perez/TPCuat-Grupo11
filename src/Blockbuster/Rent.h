#ifndef TPCUAT_GRUPO11_RENT_H
#define TPCUAT_GRUPO11_RENT_H

typedef struct Rent Rent;

struct Rent{
    int idRent;
    int idMovie;
    int dni;
    int completed;
    char* rentDate;
    char* finishDate;
};

Rent* newRent(int idRent, int idMovie, int dni, char* rentDate, char* finishDate);
void destroyRent(Rent* rent);

#endif //TPCUAT_GRUPO11_RENT_H
