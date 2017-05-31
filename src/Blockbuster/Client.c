#include <malloc.h>
#include <memory.h>
#include <stdio.h>
#include "Client.h"

/*
 * Function: newClient
 * Description: Creates a new Client with the given data.
 * Returns: Client pointer.
 */
Client* newClient(int dni, char* name, char* surname){
    Client* client = malloc(sizeof(Client));
    client->dni = dni;
    client->name = malloc(sizeof(char) * (strlen(name) + 1 ));
    strcpy(client->name, name);
    client->surname = malloc(sizeof(char) * (strlen(surname) + 1 ));
    strcpy(client->surname, surname);
    client->activeRents = createStaticList(10);
    return client;
}
/*
 * Function: destroyClient
 * Description: Deallocates all memory related to the Client.
 * Returns: --
 */
void destroyClient(Client* client){
    free(client->name);
    free(client->surname);
    freeStaticList(client->activeRents);
    free(client);
}
/*
 * Function: clientAddRent
 * Description: adds a given idRent to the Client.
 * Returns: 1 if the id was added, 0 if it wasn't.
 */
int clientAddRent(Client* client, int idRent){
    for(int i = 0; i < client->activeRents->size; i++){
        goTo(client->activeRents, i);
        if(getActual(client->activeRents) == idRent){
            return 0;
        }
    }
    goLast(client->activeRents);
    addNext(client->activeRents, idRent);
    return 1;
}
/*
 * Function: clientRemoveRent
 * Description: removes the idRent from the client.
 * Returns: --
 */
void clientRemoveRent(Client* client, int idRent){
    for(int i = 0; i < client->activeRents->size; i++){
        goTo(client->activeRents, i);
        if(getActual(client->activeRents) == idRent){
            removeS(client->activeRents);
            return;
        }
    }
}
