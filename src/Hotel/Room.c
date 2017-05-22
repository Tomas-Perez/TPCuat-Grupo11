#include <stdlib.h>
#include "Room.h"

Room* newRoom(RoomType type, int pricePerDay){
    Room* result = malloc(sizeof(Room));
    result->type = type;
    result->pricePerDay = pricePerDay;
    return result;
}

void destroyRoom(Room* room){
    free(room);
}