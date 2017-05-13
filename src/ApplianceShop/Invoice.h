#ifndef TPCUAT_GRUPO11_INVOICE_H
#define TPCUAT_GRUPO11_INVOICE_H

#include "InvoiceLine.h"
#include "Cart.h"

typedef struct Invoice{
    InvoiceLine* invoiceLines;
    int total;
}Invoice;

Invoice* newInvoice(Cart* cart);
void destroyInvoice(Invoice* invoice);

#endif //TPCUAT_GRUPO11_INVOICE_H
