#ifndef TPCUAT_GRUPO11_CARTLINE_H
#define TPCUAT_GRUPO11_CARTLINE_H

typedef struct CartLine{
    int productID;
    int amount;
}CartLine;

CartLine* newCartLine(int productID, int amount);
void destroyCartLine(CartLine* cartLine);

#endif //TPCUAT_GRUPO11_CARTLINE_H
