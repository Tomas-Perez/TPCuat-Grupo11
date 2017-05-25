#include <stdio.h>
#include "../Util/ScanUtil.h"

int main() {
    char* a = scanChar();
    printf("%s\n", a);
    int b = scanInt();
    printf("%d", b);
    return 0;
}

