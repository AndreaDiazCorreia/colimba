#include <stdio.h>
#include <stdlib.h>

/*2.6 Correction*/
unsigned int setbits(unsigned int x, int p, int n, unsigned int y);

int main()
{
    printf("%u\n", setbits(170u, 4, 3, 7u));
    return EXIT_SUCCESS;
}

unsigned int setbits(unsigned int x, int p, int n, unsigned int y)
{
    unsigned int i, mask, j;

    i = (x >> (p+1-n)) & ~(~0u << n);

    mask = ~(((1u << n)-1u) << (p+1-n));

    j = mask & x;

    return j | (i << (p+1-n));
}
