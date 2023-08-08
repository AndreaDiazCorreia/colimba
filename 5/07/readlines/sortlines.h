#ifndef SORTLINES_H
#define SORTLINES_H

#define MAXLINES 5000
#define MAXLEN 1000
#define MAXSTOR 5000

int readlines(char *lineptr[], char *linestor, int maxlines);
void writelines(char *lineptr[], int nlines);
void qsort(char *v[], int left, int right);
int mgetline(char *s, int lim);

#endif /* SORTLINES_H */
