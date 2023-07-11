#include <stdio.h>
#include <stdlib.h>

/*2.10*/
int lower(int c);

int main(void) {
    int c;

    while ((c = getchar()) != EOF) {
        putchar(lower(c));
    }
}

int lower(int c) { return c >= 'A' && c <= 'Z' ? c + 'a' - 'A' : c; }
