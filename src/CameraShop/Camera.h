#ifndef TPCUAT_GRUPO11_CAMERA_H
#define TPCUAT_GRUPO11_CAMERA_H

#include "../structs/StaticList.h"

typedef enum{DSLR, COMPACT}CameraType;

typedef struct Camera{
    char* name;
    int productID;
    int megaPixels;
    int zoom;
    int hasLCD;
    CameraType cameraType;
    StaticList* accessoryList;
}Camera;

Camera* newCamera(char* name, int megaPixels, int zoom, int hasLCD, CameraType cameraType);
void addAccessory(Camera* camera, int accessoryID);
void removeAccessory(Camera* camera, int accessoryID);
void destroyCamera(Camera* camera);


#endif //TPCUAT_GRUPO11_CAMERA_H
