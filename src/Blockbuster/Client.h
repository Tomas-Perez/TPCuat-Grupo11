#ifndef TPCUAT_GRUPO11_CLIENT_H
#define TPCUAT_GRUPO11_CLIENT_H

#include "../structs/StaticList.h"

typedef struct Client Client;

struct Client{
    int dni;
    char* name;
    char* surname;
    StaticList* activeRents;
};

Client* newClient(int dni, char* name, char* surname);
void destroyClient(Client* client);
int clientAddRent(Client* client, int idRent);
void clientRemoveRent(Client* client, int idRent);

#endif //TPCUAT_GRUPO11_CLIENT_H
