#include <stdio.h>
#include "../Util/ScanUtil.h"
#include "BlockbusterDatabase.h"


void  newRentMenu(BlockbusterDatabase* database){
    if(database->amountOfMovies == 0){
        printf("\nThere are no movies.\n");
        return;
    }
    Movie* movieArray[database->amountOfMovies];
    printf("\n-- Movies --\n\n");
    if(database->amountOfMovies > 0) {
        for (int i = 0; i < database->amountOfMovies; i++) {
            Movie *movie = database->movies[i];
            movieArray[i] = movie;
            printf("\n%d. %s\n", i, movie->name);
            if (movie->isTaken) {
                printf("Available: No\n\n");
            }
            else {
                printf("Available: Yes\n\n");
            }
        }
    }
    printf("Dni of the client:\n");
    printf("(-1 to cancel)\n");
    int dni = 0;
    Client* client;
    while(1){
        dni = scanInt();
        if(dni == -1){
            return;
        }
        client = getClient(database, dni);
        if(client != NULL){
            break;
        }
        printf("That client does not exist\n");
    }
    printf("Client: %s %s\n", client->name, client->surname);
    int movie = 0;
    while(1){
        printf("\nInsert number of the movie to borrow:\n");
        movie = scanInt();
        if(movie == -1){
            return;
        }
        if(movie > 0 && movie <= database->amountOfMovies){
            if(movieArray[movie-1]->isTaken){
                printf("That movie is already borrowed\n");
            } else{
                printf("- Dates -\n");
                printf("From:\n");
                char* from = scanChar();
                printf("Until:\n");
                char* until = scanChar();
                movieArray[movie-1]->isTaken = 1;
                Rent* rent = newRent(generateIdRent(database),movieArray[movie-1]->idMovie,client->dni,from,until);
                addRent(database, rent);
                clientAddRent(client, movieArray[movie-1]->idMovie);
                printf("Movie \"%s\" borrowed by %s %s.\n", movieArray[movie-1]->name, client->name, client->surname);
            }
        } else{
            printf("Please insert a valid number.\n");
        }
    }
}


void adminMenu(BlockbusterDatabase* database){
    while(1) {
        printf("\n-- BlockBuster --\n");
        printf("1. New Rent\n");
        printf("2. Return movie\n");
        printf("3. Add movie\n");
        printf("4. Remove movie\n");
        printf("5. Rents report\n");
        printf("-1. exit\n");
        int choice = scanInt();
        switch (choice) {
            case 1:
                newRentMenu(database);
                break;
            case 2:
                returnMovieMenu(database);
                break;
            case 3:
                addMovieMenu(database);
                break;
            case 4:
                removeMovieMenu(database);
                break;
            case 5:
                rentReportMenu(database);
                break;
            case -1:
                return;
            default:
                printf("Please enter one of the options\n");
        }
    }
}