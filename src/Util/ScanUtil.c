#include <stdio.h>
#include <memory.h>
#include <malloc.h>
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
    char* line = malloc(sizeof(char) * 256);
    int empty = 1;
    while(empty) {
        if (fgets(line, sizeof(line), stdin) && strlen(line) != 1) {
            return line;
        }
        else {
            printf("Please enter a string");
        }
    }
}