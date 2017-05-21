#include <stdlib.h>
#include "Room.h"

Room* newRoom(int number, RoomType type, int pricePerDay){
    Room* result = malloc(sizeof(Room));
    result->number = number;
    result->type = type;
    result->pricePerDay = pricePerDay;
    return result;
}

void destroyRoom(Room* room){
    free(room);
}