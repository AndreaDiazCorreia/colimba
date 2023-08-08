#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tail.h"

/* error: print error messages and exit */
void error(char *s) {
    printf("%s\n", s);
    exit(1);
}

/* mgetline: read a line into s and return length */
int mgetline(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}
