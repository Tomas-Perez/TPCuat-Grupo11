#include <malloc.h>
#include "CartLine.h"

CartLine* newCartLine(int applianceId, int amount){
    CartLine* result = malloc(sizeof(CartLine));
    result->applianceId = applianceId;
    result->amount = amount;

    return result;
}

void destroyCartLine(CartLine* cartLine){
    free(cartLine);
}