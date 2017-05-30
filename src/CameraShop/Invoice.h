#ifndef TPCUAT_GRUPO11_INVOICE_H
#define TPCUAT_GRUPO11_INVOICE_H

#include "InvoiceLine.h"
#include "../structs/StaticList.h"

/*
 * Description: Represents an invoice for a CameraShop purchase.
 */
typedef struct Invoice{
    int invoiceID;
    InvoiceLine** invoiceLines;
    int amountOfLines;
    int total;
}Invoice;

Invoice* newInvoice(int total, InvoiceLine** invoiceLines, int amountOfLines);
void destroyInvoice(Invoice* invoice);

#endif //TPCUAT_GRUPO11_INVOICE_H
