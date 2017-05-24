#include <stdio.h>
#include "Room.h"

int main() {
    char line[256];
    int i;
    int NaN = 1;
    while(NaN) {
        if (fgets(line, sizeof(line), stdin)) {
            if (1 == sscanf(line, "%d", &i)) {
                printf("%d", i);
                NaN = 0;
            }
            else {
                printf("NaN u fcker");
            }
        }
    }
    return 0;
}