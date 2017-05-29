#include <malloc.h>
#include <memory.h>
#include "Rent.h"

Rent* newRent(int idRent, int idMovie, int dni, char* rentDate, char* finishDate){
    Rent* rent = malloc(sizeof(Rent));
    rent->idRent = idRent;
    rent->idMovie = idMovie;
    rent->dni = dni;
    rent->completed = 0;
    rent->rentDate = malloc(sizeof(char) * (strlen(rentDate) + 1 ));
    strcpy(rent->rentDate, rentDate);
    rent->finishDate = malloc(sizeof(char) * (strlen(finishDate) + 1 ));
    strcpy(rent->finishDate, finishDate);
    return rent;
}

void destroyRent(Rent* rent){
    free(rent->rentDate);
    free(rent->finishDate);
    free(rent);
}
