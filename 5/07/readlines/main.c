#include <stdio.h>
#include "sortlines.h"

/*5.7*/

char *lineptr[MAXLINES];
char linestor[MAXSTOR];

int main(void) {
    int nlines;

    if ((nlines = readlines(lineptr, linestor, MAXLINES)) >= 0) {
        qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
}
