#include <stdio.h>
#include <stdlib.h>

#define TRUE  1
#define FALSE 0

/*3.2*/

void escape(char s[], const char t[]);
void unescape(char s[], const char t[]);

int main()
{
    int i;
    char c, s[1024], t[1024];

    i = 0;
    while ((c = getchar()) != EOF)
        t[i++] = c;
    t[i] = '\0';

    printf(">%s\n", t);
    escape(s, t);
    printf(">%s\n", s);
    unescape(t, s);
    printf(">%s\n", t);

    return EXIT_SUCCESS;
}

/* converts newlines and tabs into visible escape sequences */
void escape(char s[], const char t[])
{
    int i, j;

    for (i = j = 0; t[i] != '\0'; ++i) {
        switch (t[i]) {
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                break;
            default:
                s[j++] = t[i];
                break;
        }
    }
    s[j] = '\0';
}

/* converts escape sequenes '\n' and '\t' into newlines and tabs into as it copies the string t into s */
void unescape(char s[], const char t[])
{
    int i, j;
    int slash;

    slash = FALSE;
    for (i = j = 0; t[i] != '\0'; ++i) {
        switch (t[i]) {
            case '\\':
                slash = TRUE;
                break;
            case 'n':
                if (slash) {
                    s[j++] = '\n';
                    slash = FALSE;
                    break;
                }
                else {
                    s[j++] = t[i];
                    break;
                }
            case 't':
                if (slash) {
                    s[j++] = '\t';
                    slash = FALSE;
                    break;
                }
                else {
                    s[j++] = t[i];
                    break;
                }
            default:
                s[j++] = t[i];
                break;
        }
    }
    s[j] = '\0';
}
