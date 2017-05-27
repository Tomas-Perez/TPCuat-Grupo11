#include "HotelClient.h"
#include <malloc.h>
#include <memory.h>

/*
 * Description: File containing functions related to the HotelClient ADT.
 */

/*
 * Function: newHotelClient.
 * Description: creates a new HotelClient.
 * Returns: HotelClient pointer.
 */

HotelClient* newHotelClient(char* name, char* surname, int DNI){
    HotelClient* result = malloc(sizeof(HotelClient));
    result->DNI = DNI;
    result->name = malloc(sizeof(char)*strlen(name) + 1);
    strcpy(result->name, name);
    result->surname = malloc(sizeof(char)*strlen(surname) + 1);
    strcpy(result->surname, surname);

    return result;
}

/*
 * Function: destroyHotelClient.
 * Description: deallocates memory assigned to the HotelClient.
 * Returns: --
 */
void destroyHotelClient(HotelClient* client){
    free(client->name);
    free(client->surname);
    free(client);
}