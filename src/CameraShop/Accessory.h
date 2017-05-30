#ifndef TPCUAT_GRUPO11_ACCESSORY_H
#define TPCUAT_GRUPO11_ACCESSORY_H

/*
 * Description: Represents a camera accessory in the Camera Shop system.
 */

typedef struct Accessory{
    char* name;
    int productID;
    char* comment;
}Accessory;

Accessory* newAccessory(char *name, char *comment);
void destroyAccessory(Accessory* accessory);

#endif //TPCUAT_GRUPO11_ACCESSORY_H
