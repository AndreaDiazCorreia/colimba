#include <stdio.h>
#include <string.h>

#define MAXLINE 100

/*4.13*/
int mgetline(char line[], int lim);
void reverse_helper(char s[], int i, int len);

void reverse(char s[]) {
    int len = strlen(s);
    reverse_helper(s, 0, len);
}

void reverse_helper(char s[], int i, int len) {
    if (i >= len / 2) {
        return;
    }

    int j = len - (i + 1);
    char c = s[i];
    s[i] = s[j];
    s[j] = c;

    reverse_helper(s, i + 1, len);
}

int main(void) {
    char s[MAXLINE];
    mgetline(s, MAXLINE);

    reverse(s);

    printf("%s", s);

    return 0;
}

int mgetline(char line[], int lim) {
    int i, c;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;

    if (c == '\n')
        line[i++] = '\n';

    line[i] = '\0';
}
