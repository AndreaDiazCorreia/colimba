#include <stdio.h>

#define MAXLINE 1000

/*5.3*/

int mgetline(char line[], int lim);
void custom_strcat(char *, char *);

int main(void) {
    char s[MAXLINE], t[MAXLINE];

    printf("s:");
    mgetline(s, MAXLINE);

    printf("t:");
    mgetline(t, MAXLINE);

    custom_strcat(s, t);

    printf("%s", s);

    return 0;
}

int mgetline(char line[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;

    if (c == '\n') {
        line[i] = c;
        ++i;
    }

    line[i] = '\0';

    return i;
}

void custom_strcat(char *s, char *t) {
    /* Advance to the end of s*/
    while (*s)
        s++;

    /* Copy t at the end of s*/
    while ((*s = *t)) {
        s++;
        t++;
    }
}
