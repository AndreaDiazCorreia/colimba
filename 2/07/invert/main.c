#include <stdio.h>
#include <stdlib.h>

/*2.7*/
unsigned invert(unsigned x, int p, int n);

int main(void)
{
    printf("%u\n", invert(240, 4, 3));
    return EXIT_SUCCESS;
}

unsigned invert(unsigned x, int p, int n)
{
    int mask;

    mask = (~(~0U << n)) << (p-n+1);
    return mask ^ x;
}
