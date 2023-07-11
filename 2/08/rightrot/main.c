#include <stdio.h>
#include <stdlib.h>

/*2.8*/
unsigned rightrot(unsigned x, int n);

int main() {
    unsigned x = 23589;
    int n = 6;

    unsigned result = rightrot(x, n);
    printf("result: %u\n", result);

    return 0;
}

unsigned rightrot(unsigned x, int n) {

    int rightmostN = ~(~0 << n);


    int captured = x & rightmostN;


    int captured_shifted = captured << (16 - n);

    int shifted = x >> n;


    return shifted | captured_shifted;
}
