#include "Camera.h"
#include <stdlib.h>
#include <string.h>

Camera* newCamera(char* name, int megaPixels, int zoom, int hasLCD, CameraType cameraType){
    Camera* result = malloc(sizeof(Camera));
    result->name = malloc(sizeof(char)*(strlen(name)+1));
    strcpy(result->name, name);
    result->megaPixels = megaPixels;
    result->zoom = zoom;
    result->hasLCD = hasLCD;
    result->cameraType = cameraType;
    result->accessoryList = createStaticList(5);
    return result;
}
void addAccessory(Camera* camera, int accessoryID){
    StaticList* list = camera->accessoryList;
    goLast(list);
    addNext(list, accessoryID);
}
void removeAccessory(Camera* camera, int accessoryID){
    StaticList* list = camera->accessoryList;
    for(int i = 0; i < list->size; i++){
        goTo(list, 0);
        if(getActual(list) == accessoryID) {
            removeS(list);
            break;
        }
    }
}
void destroyCamera(Camera* camera){
    free(camera->name);
    freeStaticList(camera->accessoryList);
    free(camera);
}