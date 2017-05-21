#ifndef TPCUAT_GRUPO11_HOTELCLIENT_H
#define TPCUAT_GRUPO11_HOTELCLIENT_H

typedef struct HotelClient{
    char* name;
    char* surname;
    int DNI;
    int clientID;
}HotelClient;

HotelClient* newHotelClient(char* name, char* surname, int DNI, int clientID);
void destroyHotelClient(HotelClient* client);

#endif //TPCUAT_GRUPO11_HOTELCLIENT_H
