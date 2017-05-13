#include <malloc.h>
#include "InvoiceLine.h"

InvoiceLine* newInvoiceLine(CartLine* cartLine){
    InvoiceLine* invoiceLine = malloc(sizeof(InvoiceLine));
    invoiceLine->applianceId = cartLine->applianceId;
    invoiceLine->amount = cartLine->amount;
    return invoiceLine;
}
void destroyInvoiceLine(InvoiceLine* invoiceLine){
    free(invoiceLine);
}