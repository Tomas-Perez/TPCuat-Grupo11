#include <malloc.h>
#include <memory.h>
#include "Client.h"


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
void destroyClient(Client* client){
    free(client->name);
    free(client->surname);
    freeStaticList(client->activeRents);
    free(client);
}
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
void clientRemoveRent(Client* client, int idRent){
    StaticList* list = client->activeRents;
    for(int i = 0; i < list->size; i++){
        goTo(list, i);
        if(getActual(list) == idRent){
            removeS(list);
            break;
        }
    }
}
