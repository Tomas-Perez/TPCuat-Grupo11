#include <stdio.h>
#include "../Util/ScanUtil.h"
#include "BlockbusterDatabase.h"


void adminMenu(BlockbusterDatabase* blockBuster){
    while(1) {
        printf("\n-- BlockBuster --\n");
        printf("1. New Rent\n");
        printf("2. Return movie\n");
        printf("3. Add movie\n");
        printf("4. Remove movie\n");
        printf("5. Rents report\n");
        printf("-1. exit\n");
        int choice = scanInt();
        switch (choice) {
            case 1:
                listMaterialMenu(blockBuster);
                break;
            case 2:
                listBorrowedMaterialMenu(blockBuster);
                break;
            case 3:
                addMaterialMenu(blockBuster);
                break;
            case 4:
                removeMaterialMenu(blockBuster);
                break;
            case 5:
                borrowReportMenu(blockBuster);
                break;
            case -1:
                return;
            default:
                printf("Please enter one of the options\n");
        }
    }
}