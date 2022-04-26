#include "std_lib_facilities.h"

// Compile: g++ ch27.c -o ch27

void printout (char* p, int x) {
    printf("p is \"%s\" and x is %i", p, x);
    return;
}

int main() {
    char hello[] = "Hello";
    char world[] = "World!";
    printf("%s %s\n", hello, world);

    char po_char[] = "foo";
    int po_int = 7;
    printout(po_char, po_int);
    return 0;
} 