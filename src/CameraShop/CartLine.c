#include <malloc.h>
#include "CartLine.h"

CartLine* newCartLine(int productID, int amount){
    CartLine* result = malloc(sizeof(CartLine));
    result->productID = productID;
    result->amount = amount;

    return result;
}

void destroyCartLine(CartLine* cartLine){
    free(cartLine);
}