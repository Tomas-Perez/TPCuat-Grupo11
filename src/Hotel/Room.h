#ifndef TPCUAT_GRUPO11_ROOM_H
#define TPCUAT_GRUPO11_ROOM_H

typedef enum {SINGLE, DELUXE, MASTER}RoomType;

typedef struct Room{
    int number;
    RoomType type;
    int pricePerDay;
}Room;

Room* newRoom(RoomType type, int pricePerDay);
void destroyRoom(Room* room);

#endif //TPCUAT_GRUPO11_ROOM_H
