#include <stdio.h>

#define MAXLINE 1000

/*5.4*/

int mgetline(char s[], int lim);
int strend(char *s, char *t);
int mystrlen(char *t);

int main(void) {
    char s[MAXLINE], t[MAXLINE];
    int ret;
    mgetline(s, MAXLINE);
    mgetline(t, MAXLINE);
    ret = strend(s, t);
    printf("%d\n", ret);
    return 0;
}

int mgetline(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && ((c = getchar()) != EOF) && c != '\n'; ++i)
        s[i] = c;

    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';

    return i;
}

int strend(char *s, char *t) {
    int len_s = mystrlen(s);
    int len_t = mystrlen(t);

    if (len_t > len_s) {
        return 0;
    }

    s += len_s - len_t;

    while (*s && *t) {
        if (*s != *t) {
            return 0;
        }
        s++;
        t++;
    }

    return (*t == '\0');
}

int mystrlen(char *t) {
    char *p = t;
    while (*p != '\0')
        ++p;
    return p - t;
}
