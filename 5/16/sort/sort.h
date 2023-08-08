#ifndef SORT_H
#define SORT_H

#include <ctype.h>

#define NUMERIC   1    /* numeric sort */
#define DECR      2    /* sorts in decreasing order */
#define FOLD      4    /* fold upper and lower case */
#define LINES     100    /* max # of lines to be sorted */
#define MAXLEN    1000   /* max length of any input line */
#define DIRECTORY  8    /* directory order */

extern char option;
int mystrcmp(char *, char *);
int numcmp(char *, char *);
int readlines(char *lineptr[], int maxlines);
void myqsort(void *v[], int left, int right, int (*comp)(void *, void *));
void writelines(char *lineptr[], int nlines, int decr);

#endif
