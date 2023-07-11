#include <stdio.h>
#include <stdlib.h>

/*2.9*/
int bitcount(unsigned x);

int main(void) { printf("%d", bitcount((unsigned) 12)); }

int bitcount(unsigned x) {
    int b;

    for (b = 0; x != 0; x &= x - 1)
        ++b;

    return b;
}

/*The bitcount function counts the number of bits set in an unsigned integer using the observation that x &= (x-1) clears the rightmost bit 1 in x.

The bitcount function uses a while loop to iterate over the bits set in x. At each iteration, the rightmost bit 1 in x is cleared using the above
observation and a counter is incremented. The loop terminates when all the bits set in x have been counted.
*/
