#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000

/*1.18*/
int getline(char line[], int lim);

int removetrail(char rline[]);

int main(void) {
    int len;
    char line[MAXLINE];

    while ((len = getline(line, MAXLINE)) > 0)
        if (removetrail(line) > 0)
            printf("%s", line);

    return 0;
}

int getline(char line[], int lim) {
    int i, c;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';

    return i;
}


int removetrail(char rline[]) {
    int i;

    for (i = 0; rline[i] != '\n'; ++i);
    --i;

    for (i > 0; ((rline[i] == ' ') || (rline[i] == '\t')); --i);

    if (i >= 0)
    {
        ++i;
        rline[i] = '\n';
        ++i;
        rline[i] = '\0';
    }
    return i;
}
