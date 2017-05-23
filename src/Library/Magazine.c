#include <malloc.h>
#include "Magazine.h"

Magazine* newMagazine(int idMaterial){
    Magazine* magazine = malloc(sizeof(Magazine));
    magazine->idMaterial = idMaterial;
    return magazine;
}
void destroyMagazine(Magazine* magazine){
    free(magazine);
}
