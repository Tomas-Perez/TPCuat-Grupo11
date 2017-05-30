#include <stdio.h>
#include <memory.h>
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
            printf("%d. %s\n", i+1, movie->name);
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
        printf("\nInsert number of the movie to rent:\n");
        printf("(-1 to finish)\n");
        movie = scanInt();
        if(movie == -1){
            return;
        }
        if(movie > 0 && movie <= database->amountOfMovies){
            if(movieArray[movie-1]->isTaken){
                printf("That movie is already rented\n");
            } else{
                printf("- Dates -\n");
                printf("From:\n");
                char* from = scanChar();
                printf("Until:\n");
                char* until = scanChar();
                movieArray[movie-1]->isTaken = 1;
                Rent* rent = newRent(generateIdRent(database),movieArray[movie-1]->idMovie,client->dni,from,until);
                addRent(database, rent);
                clientAddRent(client, rent->idRent);
                printf("Movie \"%s\" rented by %s %s.\n", movieArray[movie-1]->name, client->name, client->surname);
            }
        } else{
            printf("Please insert a valid number.\n");
        }
    }
}
void returnMovieMenu(BlockbusterDatabase* database){
    printf("\n-- Return movie --\n\n");
    printf("Dni of the client:\n");
    printf("(-1 to cancel)\n\n");
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
    if(client->activeRents->size == 0){
        printf("\nThe client does not have any active rents.\n");
        return;
    }

    Rent* rentArray[client->activeRents->size];
    printf("\n-- %s movies --\n\n", client->name);
    for (int i = 0; i < client->activeRents->size; i++) {
        goTo(client->activeRents, i);
        Rent* rent = getRent(database, getActual(client->activeRents));
        rentArray[i] = rent;
        printf("%d. %s\n", i+1, getMovie(database, rent->idMovie)->name);
    }
    int rentChoice = 0;
    while(1){
        printf("\nInsert number of the movie to return:\n");
        printf("(0 to return all, -1 to cancel):\n");
        rentChoice = scanInt();
        if(rentChoice == -1){
            return;
        }
        if(rentChoice > 0 && rentChoice <= client->activeRents->size){
            if(rentArray[rentChoice-1]->completed){
                printf("That movie was already returned\n");
            }
            else{
                Movie* movie = getMovie(database, rentArray[rentChoice-1]->idMovie);
                movie->isTaken = 0;
                rentArray[rentChoice-1]->completed = 1;
                clientRemoveRent(client, rentArray[rentChoice-1]->idRent);
                printf("Movie \"%s\" Returned by %s %s.\n", movie->name, client->name, client->surname);
            }
        }
        else if(rentChoice == 0) {
            int size = client->activeRents->size;
            for (int i = 0; i < size; i++) {
                Movie* movie = getMovie(database, rentArray[i]->idMovie);
                movie->isTaken = 0;
                rentArray[i]->completed = 1;
                clientRemoveRent(client, rentArray[i]->idRent);
                printf("Movie \"%s\" Returned by %s %s.\n", movie->name, client->name, client->surname);
            }
            return;
        }
        else{
            printf("Please insert a valid number.\n");
        }
    }
}
void addMovieMenu(BlockbusterDatabase* database){
    printf("\n-- Add Movie --\n");
    printf("(-1 to cancel)\n");
    while (1) {
        printf("Title:\n");
        char *title = scanChar();
        if (strcmp(title, "-1") == 0) {
            return;
        }
        if (getMovieByName(database, title) != NULL) {
            printf("There is a movie with that title already\n");
        } else {
            Movie *movie = newMovie(generateIdMovie(database), title);
            addMovie(database, movie);
            printf("Movie added successfully\n");
            return;
        }
    }
}
void removeMovieMenu(BlockbusterDatabase* database){
    if(database->amountOfMovies == 0){
        printf("\nThere are no movies.\n");
        return;
    }
    Movie* movieArray[database->amountOfMovies];
    printf("\n-- Remove movies --\n\n");
    if(database->amountOfMovies > 0) {
        for (int i = 0; i < database->amountOfMovies; i++) {
            Movie *movie = database->movies[i];
            movieArray[i] = movie;
            printf("\n%d. %s\n", i+1, movie->name);
        }
    }
    int movieChoice = 0;
    while(1){
        printf("\nInsert number of the movie to remove:\n");
        movieChoice = scanInt();
        if(movieChoice == -1){
            return;
        }
        if(movieChoice > 0 && movieChoice <= database->amountOfMovies){
            removeMovie(database, movieArray[movieChoice-1]->idMovie);
            printf("Movie removed.\n");
            return;
        }
    }
}
void rentReportMenu(BlockbusterDatabase* database){
    if(database->amountOfRents == 0){
        printf("\nThere are no rents.\n");
        return;
    }
    printf("\n-- Rent report --\n");
    for(int i = 0; i<database->amountOfRents;i++){
        Rent* rent = database->rents[i];
        Movie* movie = getMovie(database, rent->idMovie);
        Client* client = getClient(database, rent->dni);
        printf("Client: %s %s\n", client->name, client->surname);
        printf("Movie: %s\n", movie->name);
        printf("Start date: %s\n", rent->rentDate);
        printf("Finish date: %s\n", rent->finishDate);
        if(rent->completed){
            printf("Completed: Yes\n\n");
        } else{
            printf("Completed: No\n\n");
        }
    }
    printf("Total income: %d\n\n", database->income);
    printf("------\n\n");
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