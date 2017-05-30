#include <malloc.h>
#include "CartLine.h"

/*
 * Description: Contains the functions related to the Cartline ADT.
 */

/*
 * Function: newCartLine
 * Description: creates a new cart line with the given data.
 * Returns: CartLine pointer.
 */
CartLine* newCartLine(int productID, int amount){
    CartLine* result = malloc(sizeof(CartLine));
    result->productID = productID;
    result->amount = amount;

    return result;
}

/*
 * Function: destroyCartLine
 * Description: Deallocates the memory allocated to the cartline.
 * Returns: --
 */
void destroyCartLine(CartLine* cartLine){
    free(cartLine);
}