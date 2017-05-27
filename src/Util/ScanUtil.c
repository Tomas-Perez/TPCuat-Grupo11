#include <stdio.h>
#include <memory.h>
#include <malloc.h>
#include <ctype.h>
#include "ScanUtil.h"

int scanInt(){
    char line[256];
    int i = -1;
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

static void trim(char *str) {
    int len = strlen(str);
    char *frontp = str;
    char *endp = str + len;

    while(isspace((unsigned char) *frontp)) ++frontp;
    if(endp != frontp){
        while(isspace((unsigned char) *(--endp)) && endp != frontp);
    }

    if(str + len - 1 != endp) *(endp + 1) = '\0';
    else if(frontp != str &&  endp == frontp)*str = '\0';

    endp = str;
    if(frontp != str) {
        while(*frontp) {*endp++ = *frontp++;}
        *endp = '\0';
    }
}

char* scanChar(){
    size_t bufferSize = sizeof(char) * 256;
    char* line = malloc(bufferSize);
    while(1) {
        if (fgets(line, bufferSize, stdin)) {
            trim(line);
            if(strlen(line) != 0) return line;
        }
        printf("Please enter a string\n");
    }
}