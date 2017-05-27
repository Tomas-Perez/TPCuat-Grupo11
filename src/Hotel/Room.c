#include <stdlib.h>
#include "Room.h"

/*
 * Description: Contains the functions related to the Room ADT.
 */

/*
 * Function: newRoom
 * Description: creates a new Room.
 * Returns: Room pointer.
 */

Room* newRoom(RoomType type, int pricePerDay){
    Room* result = malloc(sizeof(Room));
    result->type = type;
    result->pricePerDay = pricePerDay;
    return result;
}

/*
 * Function: destroyRoom
 * Description: deallocates all memory assigned to the room.
 * Returns: --
 */
void destroyRoom(Room* room){
    free(room);
}

/*
 * Function: getRoomType
 * Description: Takes a room and returns its type in a string.
 * Returns: char pointer to the room type string.
 */
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