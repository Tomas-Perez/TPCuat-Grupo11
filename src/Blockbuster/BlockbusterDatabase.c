#include <malloc.h>
#include <memory.h>
#include "BlockbusterDatabase.h"

BlockbusterDatabase* newBlockbusterDatabase(int initialCapacity, int rentCost){
    BlockbusterDatabase* blockbusterDatabase = malloc(sizeof(BlockbusterDatabase));

    blockbusterDatabase->income = 0;
    blockbusterDatabase->rentCost = rentCost;

    blockbusterDatabase->clients = malloc(sizeof(Client*)*initialCapacity);
    blockbusterDatabase->admins = malloc(sizeof(Admin*)*initialCapacity);
    blockbusterDatabase->movies = malloc(sizeof(Movie*)*initialCapacity);
    blockbusterDatabase->rents = malloc(sizeof(Rent*)*initialCapacity);

    blockbusterDatabase->clientMaxCapacity = initialCapacity;
    blockbusterDatabase->adminMaxCapacity = initialCapacity;
    blockbusterDatabase->movieMaxCapacity = initialCapacity;
    blockbusterDatabase->rentMaxCapacity = initialCapacity;

    blockbusterDatabase->amountOfClients = 0;
    blockbusterDatabase->amountOfAdmins = 0;
    blockbusterDatabase->amountOfMovies = 0;
    blockbusterDatabase->amountOfRents = 0;

    blockbusterDatabase->movieIdGenerator = 1;
    blockbusterDatabase->rentIdGenerator = 1;

    return blockbusterDatabase;
}

void destroyBlockbusterDatabase(BlockbusterDatabase* blockbusterDatabase){
    for(int i = 0; i < blockbusterDatabase->amountOfClients; i++){
        destroyClient (blockbusterDatabase->clients[i]);
    }
    free(blockbusterDatabase->clients);
    for(int i = 0; i < blockbusterDatabase->amountOfAdmins; i++){
        destroyAdmin (blockbusterDatabase->admins[i]);
    }
    free(blockbusterDatabase->admins);
    for(int i = 0; i < blockbusterDatabase->amountOfMovies; i++){
        destroyMovie (blockbusterDatabase->movies[i]);
    }
    free(blockbusterDatabase->movies);
    for(int i = 0; i < blockbusterDatabase->amountOfRents; i++){
        destroyRent (blockbusterDatabase->rents[i]);
    }
    free(blockbusterDatabase->rents);
    free(blockbusterDatabase);
}

static void growClients(BlockbusterDatabase* blockbusterDatabase){
    blockbusterDatabase->clients = realloc(blockbusterDatabase->clients, sizeof(Client*) * blockbusterDatabase->clientMaxCapacity*2);
    blockbusterDatabase->clientMaxCapacity *= 2;
}

static void growAdmins(BlockbusterDatabase* blockbusterDatabase){
    blockbusterDatabase->admins = realloc(blockbusterDatabase->admins, sizeof(Admin*) * blockbusterDatabase->adminMaxCapacity*2);
    blockbusterDatabase->adminMaxCapacity *= 2;
}

static void growMovies(BlockbusterDatabase* blockbusterDatabase){
    blockbusterDatabase->movies = realloc(blockbusterDatabase->movies, sizeof(Movie*) * blockbusterDatabase->movieMaxCapacity*2);
    blockbusterDatabase->movieMaxCapacity *= 2;
}

static void growRents(BlockbusterDatabase* blockbusterDatabase){
    blockbusterDatabase->rents = realloc(blockbusterDatabase->rents, sizeof(Rent*) * blockbusterDatabase->rentMaxCapacity*2);
    blockbusterDatabase->rentMaxCapacity *= 2;
}

int addClient(BlockbusterDatabase* blockbusterDatabase, Client* client){
    if(getClient(blockbusterDatabase, client->dni) != NULL)
        return 0;
    if(blockbusterDatabase->amountOfClients == blockbusterDatabase->clientMaxCapacity){
        growClients(blockbusterDatabase);
    }
    blockbusterDatabase->clients[blockbusterDatabase->amountOfClients] = client;
    blockbusterDatabase->amountOfClients++;
    return 1;
}

int addAdmin(BlockbusterDatabase* blockbusterDatabase, Admin* admin){
    if(getAdmin(blockbusterDatabase, admin->dni) != NULL)
        return 0;
    if(blockbusterDatabase->amountOfAdmins == blockbusterDatabase->adminMaxCapacity){
        growAdmins(blockbusterDatabase);
    }
    blockbusterDatabase->admins[blockbusterDatabase->amountOfAdmins] = admin;
    blockbusterDatabase->amountOfAdmins++;
    return 1;
}

int addMovie(BlockbusterDatabase* blockbusterDatabase, Movie* movie){
    if(getMovie(blockbusterDatabase, movie->idMovie) != NULL)
        return 0;
    if(blockbusterDatabase->amountOfMovies == blockbusterDatabase->movieMaxCapacity){
        growMovies(blockbusterDatabase);
    }
    blockbusterDatabase->movies[blockbusterDatabase->amountOfMovies] = movie;
    blockbusterDatabase->amountOfMovies++;
    return 1;
}

int addRent(BlockbusterDatabase* blockbusterDatabase, Rent* rent){
    if(getRent(blockbusterDatabase, rent->idRent) != NULL)
        return 0;
    if(blockbusterDatabase->amountOfRents == blockbusterDatabase->rentMaxCapacity){
        growRents(blockbusterDatabase);
    }
    blockbusterDatabase->rents[blockbusterDatabase->amountOfRents] = rent;
    blockbusterDatabase->amountOfRents++;
    blockbusterDatabase->income += blockbusterDatabase->rentCost;
    return 1;
}

void removeClient(BlockbusterDatabase* blockbusterDatabase, int dni){
    for(int i = 0; i < blockbusterDatabase->amountOfClients; i++){
        if(blockbusterDatabase->clients[i]->dni == dni){

            for(int k = 0; k < blockbusterDatabase->clients[i]->activeRents->size; k++){
                goTo(blockbusterDatabase->clients[i]->activeRents, k);
                getMovie(blockbusterDatabase,
                         getRent(blockbusterDatabase, getActual(blockbusterDatabase->clients[i]->activeRents))->idMovie)->isTaken = 0;
            }

            for(int j = 0; j < blockbusterDatabase->amountOfRents; j++){
                if(blockbusterDatabase->rents[j]->dni == dni){
                    removeRent(blockbusterDatabase, blockbusterDatabase->rents[j]->idRent);
                }
            }
            destroyClient(blockbusterDatabase->clients[i]);
            for(; i < blockbusterDatabase->amountOfClients - 1; i++){
                blockbusterDatabase->clients[i] = blockbusterDatabase->clients[i+1];
            }
            blockbusterDatabase->amountOfClients--;
            break;
        }
    }
}

void removeAdmin(BlockbusterDatabase* blockbusterDatabase, int dni){
    for(int i = 0; i < blockbusterDatabase->amountOfAdmins; i++){
        if(blockbusterDatabase->admins[i]->dni == dni){
            destroyAdmin(blockbusterDatabase->admins[i]);
            for(; i < blockbusterDatabase->amountOfAdmins - 1; i++){
                blockbusterDatabase->admins[i] = blockbusterDatabase->admins[i+1];
            }
            blockbusterDatabase->amountOfAdmins--;
            break;
        }
    }
}

void removeMovie(BlockbusterDatabase* blockbusterDatabase, int idMovie){
    for(int i = 0; i < blockbusterDatabase->amountOfMovies; i++){
        if(blockbusterDatabase->movies[i]->idMovie == idMovie){
            for(int j = 0; j < blockbusterDatabase->amountOfRents; j++){
                if(blockbusterDatabase->rents[j]->idMovie == idMovie){
                    removeRent(blockbusterDatabase, blockbusterDatabase->rents[j]->idRent);
                }
            }
            destroyMovie(blockbusterDatabase->movies[i]);
            for(; i < blockbusterDatabase->amountOfMovies - 1; i++){
                blockbusterDatabase->movies[i] = blockbusterDatabase->movies[i+1];
            }
            blockbusterDatabase->amountOfMovies--;
            break;
        }
    }
}


void removeRent(BlockbusterDatabase* blockbusterDatabase, int idRent){
    for(int i = 0; i < blockbusterDatabase->amountOfRents; i++){
        if(blockbusterDatabase->rents[i]->idRent == idRent){
            destroyRent(blockbusterDatabase->rents[i]);
            for(int k = 0; k < blockbusterDatabase->amountOfClients; k++){
                clientRemoveRent(blockbusterDatabase->clients[k], blockbusterDatabase->rents[i]->idRent);
            }
            for(; i < blockbusterDatabase->amountOfRents - 1; i++){
                blockbusterDatabase->rents[i] = blockbusterDatabase->rents[i+1];
            }
            blockbusterDatabase->amountOfRents--;
            break;
        }
    }
}

Client* getClient(BlockbusterDatabase* blockbusterDatabase, int dni){
    for(int i = 0; i < blockbusterDatabase->amountOfClients; i++) {
        if (blockbusterDatabase->clients[i]->dni == dni) return blockbusterDatabase->clients[i];
    }
    return NULL;
}

Admin* getAdmin(BlockbusterDatabase* blockbusterDatabase, int dni){
    for(int i = 0; i < blockbusterDatabase->amountOfAdmins; i++) {
        if (blockbusterDatabase->admins[i]->dni == dni) return blockbusterDatabase->admins[i];
    }
    return NULL;
}

Movie* getMovie(BlockbusterDatabase* blockbusterDatabase, int idMovie){
    for(int i = 0; i < blockbusterDatabase->amountOfMovies; i++) {
        if (blockbusterDatabase->movies[i]->idMovie == idMovie) return blockbusterDatabase->movies[i];
    }
    return NULL;
}

Movie* getMovieByName(BlockbusterDatabase* blockbusterDatabase, char* name){
    for(int i = 0; i < blockbusterDatabase->amountOfMovies; i++) {
        if (strcmp(blockbusterDatabase->movies[i]->name, name) == 0) return blockbusterDatabase->movies[i];
    }
    return NULL;
}

Rent* getRent(BlockbusterDatabase* blockbusterDatabase, int idRent){
    for(int i = 0; i < blockbusterDatabase->amountOfRents; i++) {
        if (blockbusterDatabase->rents[i]->idRent == idRent) return blockbusterDatabase->rents[i];
    }
    return NULL;
}

int generateIdMovie(BlockbusterDatabase* blockbusterDatabase){
    return blockbusterDatabase->movieIdGenerator++;
}
int generateIdRent(BlockbusterDatabase* blockbusterDatabase){
    return blockbusterDatabase->rentIdGenerator++;
}

StaticList* getActiveRents(BlockbusterDatabase* blockbusterDatabase){
    StaticList* list = createStaticList(10);
    for(int i = 0; i < blockbusterDatabase->amountOfRents; i++){
        if(blockbusterDatabase->rents[i]->completed != 0){
            goLast(list);
            addNext(list, blockbusterDatabase->rents[i]->idRent);
        }
    }
    return list;
}