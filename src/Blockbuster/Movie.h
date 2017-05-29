#ifndef TPCUAT_GRUPO11_MOVIE_H
#define TPCUAT_GRUPO11_MOVIE_H

typedef struct Movie Movie;

struct Movie{
    int idMovie;
    char* name;
    int isTaken;
};

Movie* newMovie(int idMovie, char* name);
void destroyMovie(Movie* movie);

#endif //TPCUAT_GRUPO11_MOVIE_H
