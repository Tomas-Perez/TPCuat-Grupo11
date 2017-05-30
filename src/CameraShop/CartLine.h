#ifndef TPCUAT_GRUPO11_CARTLINE_H
#define TPCUAT_GRUPO11_CARTLINE_H

/*
 * Description: contains a productID and the amount of product. It's a way to avoid duplicated
 * items in a cart.
 */

typedef struct CartLine{
    int productID;
    int amount;
}CartLine;

CartLine* newCartLine(int productID, int amount);
void destroyCartLine(CartLine* cartLine);

#endif //TPCUAT_GRUPO11_CARTLINE_H
