#ifndef TPCUAT_GRUPO11_INVOICELINE_H
#define TPCUAT_GRUPO11_INVOICELINE_H

#include "CartLine.h"

/*
 * Description: Contains a product name, price and the amount of product. It's a way to avoid duplicated
 * items in an invoice.
 */

typedef struct InvoiceLine{
    int applianceId;
    int amount;
}InvoiceLine;

InvoiceLine* newInvoiceLine(CartLine* cartLine);
void destroyInvoiceLine(InvoiceLine* invoiceLine);

#endif //TPCUAT_GRUPO11_INVOICELINE_H
