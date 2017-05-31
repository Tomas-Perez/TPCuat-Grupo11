#include <malloc.h>
#include "Magazine.h"

/*
 * Function: newMagazine
 * Description: Creates a new Magazine with the given data.
 * Returns: Magazine pointer.
 */
Magazine* newMagazine(int idMaterial){
    Magazine* magazine = malloc(sizeof(Magazine));
    magazine->idMaterial = idMaterial;
    return magazine;
}
/*
 * Function: destroyMagazine
 * Description: Deallocates all memory related to the Magazine.
 * Returns: --
 */
void destroyMagazine(Magazine* magazine){
    free(magazine);
}
