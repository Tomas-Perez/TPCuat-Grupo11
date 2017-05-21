#include "HotelClient.h"
#include <stdlib.h>
#include <string.h>

HotelClient* newHotelClient(char* name, char* surname, int DNI, int clientID){
    HotelClient* result = malloc(sizeof(HotelClient));
    result->DNI = DNI;
    result->clientID = clientID;
    result->name = malloc(sizeof(char)*strlen(name) + 1);
    strcpy(result->name, name);
    result->surname = malloc(sizeof(char)*strlen(surname) + 1);
    strcpy(result->surname, surname);

    return result;
}
void destroyHotelClient(HotelClient* client){
    free(client->name);
    free(client->surname);
    free(client);
}