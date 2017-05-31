#include <malloc.h>
#include <memory.h>
#include "Rent.h"

/*
 * Function: newRent
 * Description: Creates a new Rent with the given data.
 * Returns: Rent pointer.
 */
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
/*
 * Function: destroyRent
 * Description: Deallocates all memory related to the Rent.
 * Returns: --
 */
void destroyRent(Rent* rent){
    free(rent->rentDate);
    free(rent->finishDate);
    free(rent);
}
