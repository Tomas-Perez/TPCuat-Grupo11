#include <malloc.h>
#include <memory.h>
#include "Movie.h"

Movie* newMovie(int idMovie, char* name){
    Movie* movie = malloc(sizeof(Movie));
    movie->idMovie = idMovie;
    movie->isTaken = 0;
    movie->name = malloc(sizeof(char) * (strlen(name) + 1 ));
    strcpy(movie->name, name);
    return movie;
}
void destroyMovie(Movie* movie){
    free(movie->name);
    free(movie);
}
