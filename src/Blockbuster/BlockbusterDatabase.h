#ifndef TPCUAT_GRUPO11_BLOCKBUSTERDATABASE_H
#define TPCUAT_GRUPO11_BLOCKBUSTERDATABASE_H

#include "../structs/StaticList.h"
#include "Client.h"
#include "Admin.h"
#include "Rent.h"
#include "Movie.h"

typedef struct BlockbusterDatabase BlockbusterDatabase;

struct BlockbusterDatabase{
    int income;

    StaticList* clientList;
    StaticList* adminList;
    StaticList* movieList;
    StaticList* rentList;

    int movieIdGenerator;
    int rentIdGenerator;
};

BlockbusterDatabase* blockbusterDatabase(int initialCapacity);
void destroyBlockbusterDatabase(BlockbusterDatabase* blockbusterDatabase);

int addClient(BlockbusterDatabase* blockbusterDatabase, Client* client);
void removeClient(BlockbusterDatabase* blockbusterDatabase, int dni);
Client* getClient(BlockbusterDatabase* blockbusterDatabase, int dni);

int addAdmin(BlockbusterDatabase* blockbusterDatabase, Admin* admin);
void removeAdmin(BlockbusterDatabase* blockbusterDatabase, int dni);
Admin* getAdmin(BlockbusterDatabase* blockbusterDatabase, int dni);

int addMovie(BlockbusterDatabase* blockbusterDatabase, Movie* movie);
void removeMovie(BlockbusterDatabase* blockbusterDatabase, int idMovie);
Movie* getMovie(BlockbusterDatabase* blockbusterDatabase, int idMovie);

int addRent(BlockbusterDatabase* blockbusterDatabase, Rent* rent);
void removeRent(BlockbusterDatabase* blockbusterDatabase, int idRent);
Rent* getRent(BlockbusterDatabase* blockbusterDatabase, int idRent);

int generateIdMovie(BlockbusterDatabase* blockbusterDatabase);
int generateIdRent(BlockbusterDatabase* blockbusterDatabase);

StaticList* getActiveRents(BlockbusterDatabase* blockbusterDatabase);
#endif //TPCUAT_GRUPO11_BLOCKBUSTERDATABASE_H
