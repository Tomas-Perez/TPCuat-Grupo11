#ifndef TPCUAT_GRUPO11_INVOICE_H
#define TPCUAT_GRUPO11_INVOICE_H

#include "InvoiceLine.h"
#include "../structs/StaticList.h"

typedef struct Invoice{
    int invoiceID;
    StaticList* invoiceLineList;
    int total;
}Invoice;

Invoice* newInvoice(int total, StaticList* invoiceLineList);
void destroyInvoice(Invoice* invoice);

#endif //TPCUAT_GRUPO11_INVOICE_H
