#include <stdio.h>
#include "getint.h"

#define SIZE 1000

/*5.1*/

int main(void) {
    int n, s, array[SIZE];

    for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++) {
        printf("storing in n = %d, getint %d\n", n, array[n]);
    }

    for (s = 0; s <= n; s++)
        printf("%d ", array[s]);

    return 0;
}
