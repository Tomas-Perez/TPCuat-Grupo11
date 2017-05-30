#include <stdio.h>
#include "BlockbusterDatabase.h"

void mainMenu(BlockbusterDatabase* database);

BlockbusterDatabase* setUp(){
    BlockbusterDatabase* database = newBlockbusterDatabase(20, 50);

    Admin* admin1 = newAdmin(11111111, "Admin", "Admin");
    Client* client1 = newClient(12345678,"John","White");
    Client* client2 = newClient(11234567,"Selina","Kyle");
    Client* client3 = newClient(11123456,"Kevin","Burger");

    addAdmin(database, admin1);
    addClient(database, client1);
    addClient(database, client2);
    addClient(database, client3);

    Movie* movie1 = newMovie(generateIdMovie(database), "Avatar");
    Movie* movie2 = newMovie(generateIdMovie(database), "Avengers");
    Movie* movie3 = newMovie(generateIdMovie(database), "King Arthur");
    Movie* movie4 = newMovie(generateIdMovie(database), "Son of Batman");
    Movie* movie5 = newMovie(generateIdMovie(database), "Interstellar");
    Movie* movie6 = newMovie(generateIdMovie(database), "John Wick");

    addMovie(database, movie1);
    addMovie(database, movie2);
    addMovie(database, movie3);
    addMovie(database, movie4);
    addMovie(database, movie5);
    addMovie(database, movie6);

    Rent* rent5 = newRent(generateIdRent(database), movie5->idMovie, client3->dni,"26/08/16","01/09/16");
    rent5->completed = 1;
    addRent(database,rent5);

    Rent* rent3 = newRent(generateIdRent(database), movie2->idMovie, client1->dni,"12/01/17","19/01/17");
    rent3->completed = 1;
    addRent(database,rent3);

    Rent* rent4 = newRent(generateIdRent(database), movie1->idMovie, client1->dni,"02/02/17","09/02/17");
    rent4->completed = 1;
    addRent(database,rent4);

    movie2->isTaken = 1;
    Rent* rent1 = newRent(generateIdRent(database), movie2->idMovie, client2->dni,"24/05/17","30/05/17");
    addRent(database, rent1);
    clientAddRent(client2, rent1->idRent);

    movie4->isTaken = 1;
    Rent* rent2 = newRent(generateIdRent(database), movie4->idMovie, client2->dni,"24/05/17","30/05/17");
    addRent(database, rent2);
    clientAddRent(client2, rent2->idRent);

    return database;
}

int main() {
    BlockbusterDatabase* database = setUp();

    mainMenu(database);
    return 0;
}