#ifndef TPCUAT_GRUPO11_HOTELCLIENT_H
#define TPCUAT_GRUPO11_HOTELCLIENT_H

/*
 * Description: The hotel client ADT contains relevant data of the a client of the Hotel system.
 */

typedef struct HotelClient{
    char* name;
    char* surname;
    int DNI;
    int clientID;
}HotelClient;

HotelClient* newHotelClient(char* name, char* surname, int DNI);
void destroyHotelClient(HotelClient* client);

#endif //TPCUAT_GRUPO11_HOTELCLIENT_H
