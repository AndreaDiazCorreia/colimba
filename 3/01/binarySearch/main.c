#include <stdio.h>
#include <stdlib.h>

/*3.1*/

int binsearch(int x, int v[], int n);

int main()
{
    int v[5] = {3, 6, 9, 12, 4};
    int x = 9;
    printf("%d\n", binsearch(x, v, 5));
    return EXIT_SUCCESS;
}

int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;

    while (low < high) {
        mid = (low + high) / 2;

        if (x <= v[mid])
            high = mid;
        else
            low = mid + 1;
    }

    if (x == v[low])
        return low;
    else
        return -1;
}
