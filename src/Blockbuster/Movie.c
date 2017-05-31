#include <malloc.h>
#include <memory.h>
#include "Movie.h"

/*
 * Function: newMovie
 * Description: Creates a new Movie with the given data.
 * Returns: Movie pointer.
 */
Movie* newMovie(int idMovie, char* name){
    Movie* movie = malloc(sizeof(Movie));
    movie->idMovie = idMovie;
    movie->isTaken = 0;
    movie->name = malloc(sizeof(char) * (strlen(name) + 1 ));
    strcpy(movie->name, name);
    return movie;
}
/*
 * Function: destroyMovie
 * Description: Deallocates all memory related to the Movie.
 * Returns: --
 */
void destroyMovie(Movie* movie){
    free(movie->name);
    free(movie);
}
