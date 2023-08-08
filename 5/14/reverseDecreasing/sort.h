#ifndef SORT_H
#define SORT_H

#define NUMERIC   1    /* numeric sort */
#define DECR      2    /* sorts in decreasing order */
#define LINES      100    /* max # of lines to be sorted */

extern char option;
int numcmp(char *, char *);
int readlines(char *lineptr[], int maxlines);
void myqsort(void *v[], int left, int right, int (*comp)(void *, void *));
void writelines(char *lineptr[], int nlines, int decr);

#endif
