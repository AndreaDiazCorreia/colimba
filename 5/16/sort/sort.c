#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"
#include "alloc.h"

char option = 0;

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines, int decr) {
    int i;
    if (decr)    /* print in decreasing order */
        for (i = nlines - 1; i >= 0; i--)
            printf("%s\n", lineptr[i]);
    else
        for (i = 0; i < nlines; i++)
            printf("%s\n", lineptr[i]);
}
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

int readlines(char *lineptr[], int maxlines) {
    int len, nlines;
    char *p, line[MAXLEN];
    nlines = 0;
    while ((len = mgetline(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else {
            line[len - 1] = '\0';    /* delete newline */
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}


int mystrcmp(char *s1, char *s2) {
    if (option & FOLD) {
        for (; tolower(*s1) == tolower(*s2); s1++, s2++) {
            if (*s1 == '\0')
                return 0;
        }
        return tolower(*s1) - tolower(*s2);
    } else if (option & DIRECTORY) {
        for (; !isalnum(*s1) && !isspace(*s1); s1++) {
            if (*s1 == '\0')
                return 0;
        }
        for (; !isalnum(*s2) && !isspace(*s2); s2++) {
            if (*s2 == '\0')
                return 0;
        }
        return *s1 - *s2;
    } else {
        return strcmp(s1, s2);
    }
}

/* myqsort: sort v[left] ... v[right] into increasing order */
void myqsort(void *v[], int left, int right, int (*comp)(void *, void *)) {
    int i, last;
    void swap(void *v[], int, int);

    if (left >= right)
        return;

    swap(v, left, (left + right) / 2);

    last = left;

    for (i = left + 1; i <= right; i++)
        if ((*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);

    myqsort(v, left, last - 1, comp);
    myqsort(v, last + 1, right, comp);
}

int numcmp(char *s1, char *s2) {
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);

    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}

void swap(void *v[], int i, int j) {
    void *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
