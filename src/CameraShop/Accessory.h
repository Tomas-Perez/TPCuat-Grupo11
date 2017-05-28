#ifndef TPCUAT_GRUPO11_ACCESSORY_H
#define TPCUAT_GRUPO11_ACCESSORY_H

typedef struct Accessory{
    char* name;
    int productID;
    char* comment;
}Accessory;

Accessory* createAccessory(char* name, char* comment);
void destroyAccessory(Accessory* accessory);

#endif //TPCUAT_GRUPO11_ACCESSORY_H
