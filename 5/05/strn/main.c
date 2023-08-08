#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*5.5*/

void mystrncpy(char *, char *, int);
void mystrncat(char *, char *, char *, int);
int mystrncmp(char *, char *, int);

int main(int argc, char *argv[]) {
    char dest[] = "ABCDEF";
    char source[] = "GHIJ";
    mystrncpy(dest, source, 4);
    printf("%s\n", dest);

    char s1[] = "ABCD";
    char t1[] = "EFGHIJ";
    char *d = (char *)malloc(sizeof(char) * (strlen(s1) + 4 + 1));
    if (d == NULL) {
        printf("unable to allocate memory \n");
        return -1;
    }
    mystrncat(s1, t1, d, 4);
    printf("%s\n", d);
    free(d);

    char s2[] = "ABCDEF";
    char t2[] = "ABC";
    int result = mystrncmp(s2, t2, 3);
    printf("%d\n", result);

    return 0;
}

void mystrncat(char *str1, char *str2, char *dest, int n) {
    while (*str1) {
        *dest++ = *str1++;
    }
    while (n-- > 0 && *str2) {
        *dest++ = *str2++;
    }
    *dest = '\0';
}

void mystrncpy(char *dest, char *source, int n) {
    while (*source && n-- > 0) {
        *dest++ = *source++;
    }
    *dest = '\0';
}

int mystrncmp(char *lhs, char *rhs, int n) {
    for (; *lhs == *rhs && n-- > 0; lhs++, rhs++) {
        if (*lhs == '\0') {
            return 0;
        }
    }
    return (*lhs - *rhs);
}
