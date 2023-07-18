#include <stdio.h>
#include <string.h>

/*4.1 better (I think)*/

int strrindex(char s[], char t[]);

int main() {
    char test[] = "hola carola";
    char pattern[] = "l";

    printf("rightmost position of \"%s\" in \"%s\": %d\n",
           pattern, test, strrindex(test, pattern));

    return 0;
}

/* strrindex: return rightmost index of t in s, -1 if none */
int strrindex(char s[], char t[]) {
    int len_s = strlen(s);
    int len_t = strlen(t);

    char *p_s = s + len_s - 1;
    char *p_t = t + len_t - 1;

    while (p_s >= s && p_t >= t) {
        if (*p_s == *p_t) {
            p_s--;
            p_t--;
        } else {
            p_s = p_s - len_t + 1;
            p_t = t + len_t - 1;
            p_s--;
        }
    }

    if (p_t < t)
        return p_s - s + 1;

    return -1;
}
