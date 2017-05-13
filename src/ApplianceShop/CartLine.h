#ifndef TPCUAT_GRUPO11_CARTLINE_H
#define TPCUAT_GRUPO11_CARTLINE_H

typedef struct CartLine{
    int applianceId;
    int amount;
}CartLine;

CartLine* newCartLine(int applianceId);
void destroyCartLine(CartLine* cartLine);

#endif //TPCUAT_GRUPO11_CARTLINE_H
