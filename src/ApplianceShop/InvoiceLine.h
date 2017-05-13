#ifndef TPCUAT_GRUPO11_INVOICELINE_H
#define TPCUAT_GRUPO11_INVOICELINE_H

#include "CartLine.h"

typedef struct InvoiceLine{
    int applianceId;
    int amount;
}InvoiceLine;

InvoiceLine* newInvoiceLine(CartLine* cartLine);
void destroyInvoiceLine(InvoiceLine* invoiceLine);

#endif //TPCUAT_GRUPO11_INVOICELINE_H
