#include <malloc.h>
#include "CartLine.h"

CartLine* newCartLine(int applianceId){
    CartLine* result = malloc(sizeof(CartLine));
    result->applianceId = applianceId;
    result->amount = 1;

    return result;
}

void destroyCartLine(CartLine* cartLine){
    free(cartLine);
}