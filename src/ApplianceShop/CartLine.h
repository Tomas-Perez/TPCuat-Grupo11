#ifndef TPCUAT_GRUPO11_CARTLINE_H
#define TPCUAT_GRUPO11_CARTLINE_H

/*
 * Description: contains a applianceID and the amount of appliances. It's a way to avoid duplicated
 * items in a cart.
 */

typedef struct CartLine{
    int applianceId;
    int amount;
}CartLine;

CartLine* newCartLine(int applianceId, int amount);
void destroyCartLine(CartLine* cartLine);

#endif //TPCUAT_GRUPO11_CARTLINE_H
