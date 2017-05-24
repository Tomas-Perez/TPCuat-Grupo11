#include <stdio.h>
#include <mem.h>
#include "ScanUtil.h"

int scanInt(){
    char line[256];
    int i;
    int NaN = 1;
    while(NaN) {
        if (fgets(line, sizeof(line), stdin)) {
            if (1 == sscanf(line, "%d", &i)) {
                NaN = 0;
            }
            else {
                printf("Please enter an integer\n");
            }
        }
    }
    return i;
}


char* scanChar(){
    char line[256];
    int empty = 1;
    while(empty) {
        if (fgets(line, sizeof(line), stdin)) {
            return line;
        }
        else {
            printf("Please enter a string");
        }
    }
}