set(applianceShop_SRCS Database.c Database.h Appliance.c Appliance.h Provider.c Provider.h Manufacturer.c Manufacturer.h CartLine.c CartLine.h Cart.c Cart.h Invoice.c Invoice.h InvoiceLine.c InvoiceLine.h ClientMenu.c AdminMenu.c)
add_library(applianceShop ${applianceShop_SRCS})
add_executable(applianceShopEXE main.c)
target_link_libraries(applianceShopEXE applianceShop)
