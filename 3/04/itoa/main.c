#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*3.4*/

void my_itoa(int n, char s[]);
void reverse(char s[]);

int main()
{
    int n = INT_MIN;
    char s[16];

    my_itoa(1337, s);
    printf("%s\n", s);
    my_itoa(n, s);
    printf("%s\n", s);

    return EXIT_SUCCESS;
}

/* my_itoa: convert n to characters in s */
void my_itoa(int n, char s[])
{
    int i, sign;
    unsigned int un;  /* use an unsigned type to avoid overflows. */

    if (n == INT_MIN) {
        un = (unsigned int)INT_MAX + 1;
        sign = -1;
    } else {
        un = (n < 0) ? -n : n;
        sign = (n < 0) ? -1 : 1;
    }

    i = 0;
    do {
        s[i++] = un % 10 + '0';
    } while (un /= 10);

    if (sign < 0)
        s[i++] = '-';

    s[i] = '\0';
    reverse(s);
}

/* reverse: reverse string s in place */
void reverse(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
