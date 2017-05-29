#include <malloc.h>
#include "BlockbusterDatabase.h"

BlockbusterDatabase* blockbusterDatabase(int initialCapacity){
    BlockbusterDatabase* blockbusterDatabase = malloc(sizeof(BlockbusterDatabase));

    blockbusterDatabase->income = 0;

    blockbusterDatabase->clientList = createStaticList(initialCapacity);
    blockbusterDatabase->adminList = createStaticList(initialCapacity);
    blockbusterDatabase->movieList = createStaticList(initialCapacity);
    blockbusterDatabase->rentList = createStaticList(initialCapacity);

    blockbusterDatabase->movieIdGenerator = 1;
    blockbusterDatabase->rentIdGenerator = 1;

    return blockbusterDatabase;
}
void destroyBlockbusterDatabase(BlockbusterDatabase* blockbusterDatabase){
    StaticList* list = blockbusterDatabase->clientList;
    for(int i = 0; i < list->size; i++){
        goTo(list, i);
        destroyClient ((Client*) getActual(list));
    }
    freeStaticList(list);

    list = blockbusterDatabase->adminList;
    for(int i = 0; i < list->size; i++){
        goTo(list, i);
        destroyAdmin ((Admin*) getActual(list));
    }
    freeStaticList(list);

    list = blockbusterDatabase->movieList;
    for(int i = 0; i < list->size; i++){
        goTo(list, i);
        destroyMovie ((Movie*) getActual(list));
    }
    freeStaticList(list);

    list = blockbusterDatabase->rentList;
    for(int i = 0; i < list->size; i++){
        goTo(list, i);
        destroyRent ((Rent*) getActual(list));
    }
    freeStaticList(list);

    free(blockbusterDatabase);
}

int addClient(BlockbusterDatabase* blockbusterDatabase, Client* client){
    if(getClient(blockbusterDatabase, client->dni) == NULL)
        return 0;
    goLast(blockbusterDatabase->clientList);
    addNext(blockbusterDatabase->clientList, (int) client);
    return 1;
}
void removeClient(BlockbusterDatabase* blockbusterDatabase, int dni){
    for(int i = 0; i < blockbusterDatabase->clientList->size; i++){
        goTo(blockbusterDatabase->clientList, i);
        Client* client = (Client*) getActual(blockbusterDatabase->clientList);
        if(client->dni == dni){

            for(int k = 0; i < client->activeRents->size; k++){
                goTo(client->activeRents, k);
                Movie* movie = getMovie(blockbusterDatabase, getRent(blockbusterDatabase ,getActual(client->activeRents))->idMovie);
                movie->isTaken = 0;
            }

            for(int j = 0; i < blockbusterDatabase->rentList->size; j++){
                goTo(blockbusterDatabase->rentList, j);
                Rent* rent = (Rent*) getActual(blockbusterDatabase->rentList);
                if(rent->dni == dni){
                    destroyRent(rent);
                    removeS(blockbusterDatabase->rentList);
                    free(rent);
                }
            }

            destroyClient(client);
            removeS(blockbusterDatabase->clientList);
            free(client);
            return;
        }
    }
}
Client* getClient(BlockbusterDatabase* blockbusterDatabase, int dni){
    for(int i = 0; i < blockbusterDatabase->clientList->size; i++){
        goTo(blockbusterDatabase->clientList, i);
        Client* client = (Client*) getActual(blockbusterDatabase->clientList);
        if(client->dni == dni){
            return client;
        }
    }
    return NULL;
}

int addAdmin(BlockbusterDatabase* blockbusterDatabase, Admin* admin){
    if(getAdmin(blockbusterDatabase, admin->dni) == NULL)
        return 0;
    goLast(blockbusterDatabase->adminList);
    addNext(blockbusterDatabase->adminList, (int) admin);
    return 1;
}
void removeAdmin(BlockbusterDatabase* blockbusterDatabase, int dni){
    for(int i = 0; i < blockbusterDatabase->adminList->size; i++){
        goTo(blockbusterDatabase->adminList, i);
        Admin* admin = (Admin*) getActual(blockbusterDatabase->adminList);
        if(admin->dni == dni){
            destroyAdmin(admin);
            removeS(blockbusterDatabase->adminList);
            free(admin);
            return;
        }
    }
}
Admin* getAdmin(BlockbusterDatabase* blockbusterDatabase, int dni){
    for(int i = 0; i < blockbusterDatabase->adminList->size; i++){
        goTo(blockbusterDatabase->adminList, i);
        Admin* admin = (Admin*) getActual(blockbusterDatabase->adminList);
        if(admin->dni == dni){
            return admin;
        }
    }
    return NULL;
}

int addMovie(BlockbusterDatabase* blockbusterDatabase, Movie* movie){
    if(getMovie(blockbusterDatabase, movie->idMovie) == NULL)
        return 0;
    goLast(blockbusterDatabase->movieList);
    addNext(blockbusterDatabase->movieList, (int) movie);
    return 1;
}
void removeMovie(BlockbusterDatabase* blockbusterDatabase, int idMovie){
    for(int i = 0; i < blockbusterDatabase->movieList->size; i++){
        goTo(blockbusterDatabase->movieList, i);
        Movie* movie = (Movie*) getActual(blockbusterDatabase->movieList);
        if(movie->idMovie == idMovie){
            for(int j = 0; i < blockbusterDatabase->rentList->size; j++){
                goTo(blockbusterDatabase->rentList, j);
                Rent* rent = (Rent*) getActual(blockbusterDatabase->rentList);
                if(rent->idMovie == idMovie){
                    removeRent(blockbusterDatabase, rent->idRent);
                    destroyRent(rent);
                    removeS(blockbusterDatabase->rentList);
                    free(rent);
                }
            }
            destroyMovie(movie);
            removeS(blockbusterDatabase->movieList);
            free(movie);
            return;
        }
    }
}
Movie* getMovie(BlockbusterDatabase* blockbusterDatabase, int idMovie){
    for(int i = 0; i < blockbusterDatabase->movieList->size; i++){
        goTo(blockbusterDatabase->movieList, i);
        Movie* movie = (Movie*) getActual(blockbusterDatabase->movieList);
        if(movie->idMovie == idMovie){
            return movie;
        }
    }
    return NULL;
}

int addRent(BlockbusterDatabase* blockbusterDatabase, Rent* rent){
    if(getRent(blockbusterDatabase, rent->idRent) == NULL)
        return 0;
    goLast(blockbusterDatabase->rentList);
    addNext(blockbusterDatabase->rentList, (int) rent);
    return 1;
}
void removeRent(BlockbusterDatabase* blockbusterDatabase, int idRent){
    for(int i = 0; i < blockbusterDatabase->rentList->size; i++){
        goTo(blockbusterDatabase->rentList, i);
        Rent* rent = (Rent*) getActual(blockbusterDatabase->rentList);
        if(rent->idRent == idRent){
            for(int k = 0; i < blockbusterDatabase->clientList->size; k++){
                goTo(blockbusterDatabase->clientList, k);
                clientRemoveRent((Client*) getActual(blockbusterDatabase->clientList), rent->idRent);
            }
            destroyRent(rent);
            removeS(blockbusterDatabase->rentList);
            free(rent);
            return;
        }
    }
}
Rent* getRent(BlockbusterDatabase* blockbusterDatabase, int idRent){
    for(int i = 0; i < blockbusterDatabase->rentList->size; i++){
        goTo(blockbusterDatabase->rentList, i);
        Rent* rent = (Rent*) getActual(blockbusterDatabase->rentList);
        if(rent->idRent == idRent){
            return rent;
        }
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
    for(int i = 0; i < blockbusterDatabase->rentList->size; i++){
        goTo(blockbusterDatabase->rentList, i);
        Rent* rent = (Rent*) getActual(blockbusterDatabase->rentList);
        if(getMovie(blockbusterDatabase, rent->idMovie)->isTaken){
            goLast(list);
            addNext(list, (int) rent);
        }
    }
}