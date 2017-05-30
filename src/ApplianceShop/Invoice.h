#ifndef TPCUAT_GRUPO11_INVOICE_H
#define TPCUAT_GRUPO11_INVOICE_H

#include "InvoiceLine.h"
#include "Cart.h"

/*
 * Description: Represents an invoice for an ApplianceShop purchase.
 */

typedef struct Invoice{
    InvoiceLine** invoiceLines;
    int amountOfLines;
    int total;
}Invoice;

Invoice* newInvoice(Cart* cart, Database* database);
void destroyInvoice(Invoice* invoice);

#endif //TPCUAT_GRUPO11_INVOICE_H
