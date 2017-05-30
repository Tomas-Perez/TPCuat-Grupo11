#include "Camera.h"
#include <stdlib.h>
#include <string.h>

/*
 * Contains functions related to the camera ADT.
 */

/*
 * Function: newCamera
 * Description: creates a new Camera from the given data.
 * Returns: --
 */

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

static int containsAccessory(Camera* camera, int accessoryID){
    StaticList* list = camera->accessoryList;
    for(int i = 0; i < list->size; i++){
        goTo(list, 0);
        if(getActual(list) == accessoryID) {
            return i;
        }
    }
    return -1;
}

/*
 * Function: addCameraAccessory
 * Description: adds an accessory id to the camera's accessory list.
 * Returns: --
 */

void addCameraAccessory(Camera* camera, int accessoryID){
    if(containsAccessory(camera, accessoryID) == -1) {
        StaticList *list = camera->accessoryList;
        goLast(list);
        addNext(list, accessoryID);
    }
}

/*
 * Function: removeCameraAccessory
 * Description: removes an accessory id from the camera's accessory list.
 * Returns: --
 */
void removeCameraAccessory(Camera* camera, int accessoryID){
    int accessoryIndex = containsAccessory(camera, accessoryID);
    if(accessoryIndex != -1){
        StaticList* list = camera->accessoryList;
        goTo(list, accessoryIndex);
        removeS(list);
    }
}

/*
 * Function: destroyCamera
 * Description: deallocates all memory assigned to the camera.
 * Returns: --
 */
void destroyCamera(Camera* camera){
    free(camera->name);
    freeStaticList(camera->accessoryList);
    free(camera);
}