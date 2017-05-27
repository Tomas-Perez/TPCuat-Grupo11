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

char* getRoomType(Room* room){
    switch (room->type){
        case SINGLE:
            return "Single\0";
        case DELUXE:
            return "Deluxe\0";
        case MASTER:
            return "Master\0";
    }
}