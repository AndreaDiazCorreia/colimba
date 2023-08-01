#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 64
#define BASE 36

/*3.5 posible correction, pending review*/

void itob(int n, char s[], int b);
void reverse(char s[]);

int main()
{
    char s[MAXLEN];
    itob(-255, s, 8);
    printf("%s\n", s);

    return EXIT_SUCCESS;
}

/* itob:  comvert n to characters in base b in s */
void itob(int n, char s[], int b)
{
    int i, sign;
    char symbols[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    if (2 > b || b > BASE) {
        strcpy(s, "Base out of range");
        return;
    }

    sign = n;
    i = 0;
    do {
        int digit = abs(n % b);
        s[i++] = symbols[digit];
    } while (n /= b);

    if (sign < 0)
        s[i++] = '-';

    s[i] = '\0';
    reverse(s);
}

/* reverse:  reverse string s in place */
void reverse(char s[])
{
    int c, i, j;

    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
