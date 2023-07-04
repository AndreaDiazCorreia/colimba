#include <stdio.h>
#include <stdlib.h>

/*2.3*/
int htoi(char s[]);

int main(void)
{
    char s[1024];
    int i, c;
    for (i=0; (c = getchar()) != '\n'; i++)
        s[i] = c;
    s[i] = '\0';
    printf("%s: %d\n", s, htoi(s));
    return EXIT_SUCCESS;
}


int htoi(char s[])
{
    int i;
    int c, n;

    n = 0;
    for (i = 0; (c = s[i]) != '\0'; ++i) {
        n *= 16;
        if (i == 0 && c == '0') {
            /* Drop the 0x of 0X from the start of the string. */
            c = s[++i];
            if (c != 'x' && c != 'X')
                --i;
        } else if (c >= '0' && c <= '9')
            /* numerical digit. */
            n += c - '0';
        else if (c >= 'a' && c <= 'f')
            /*  'a'-'f' */
            n += 10 + (c - 'a');
        else if (c >= 'A' && c <= 'F')
            /* range 'A'-'F' */
            n += 10 + (c - 'A');
        else
            /* invalid input */
            return n;
    }
    return n;
}
