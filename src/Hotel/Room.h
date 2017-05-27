#ifndef TPCUAT_GRUPO11_ROOM_H
#define TPCUAT_GRUPO11_ROOM_H

/*
 * Description: Represents a hotel room, with a price per day and category, also a room number assigned by the hotel.
 */

typedef enum {SINGLE, DELUXE, MASTER}RoomType;

typedef struct Room{
    int number;
    RoomType type;
    int pricePerDay;
}Room;

Room* newRoom(RoomType type, int pricePerDay);
void destroyRoom(Room* room);
char* getRoomType(Room* room);

#endif //TPCUAT_GRUPO11_ROOM_H
