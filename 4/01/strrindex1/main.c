#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
 /*4.1*/
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
    int i, j, k;

    for (i = strlen(s) - strlen(t); i >= 0; i--) {
        for (j=i, k=0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}
