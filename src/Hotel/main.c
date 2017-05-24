#include <stdio.h>
#include <memory.h>
#include "Room.h"
#include "../Util/ScanUtil.h"

int main() {
    char* a = scanChar();
    int b = scanInt();
    printf(a);
    printf("%d", b);
    return 0;
}