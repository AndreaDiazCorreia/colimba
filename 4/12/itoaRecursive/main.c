#include <stdlib.h>
#include<stdio.h>

#define MAXLEN 100

/*4.12*/
void itoa_recursive(int n, char s[]);


int main(void) {
    int n;
    char s[MAXLEN];

    n = 1723;

    itoa_recursive(n, s);

    printf("%s", s);

    return 0;
}

void itoa_recursive(int n, char s[]) {
    static int i;

    if (n / 10)
        itoa_recursive(n / 10, s);
    else {
        i = 0;
        if (n < 0)
            s[i++] = '-';
    }

    s[i++] = abs(n) % 10 + '0';

    s[i] = '\0';

}

