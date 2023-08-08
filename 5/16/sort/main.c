#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/*5.16*/

int main(int argc, char *argv[]) {
    char *lineptr[LINES];
    int nlines;        /* pointer to text lines */
    int c, rc = 0;        /* number of input lines read */

   while (--argc > 0 && (*++argv)[0] == '-')
    while (c = *++argv[0])
        switch (c) {
            case 'n': /* numeric sort */
                option |= NUMERIC;
                break;
            case 'r': /* sort in decreasing order */
                option |= DECR;
                break;
            case 'f': /* fold upper and lower case */
                option |= FOLD;
                break;
            case 'd': /* directory order */
                option |= DIRECTORY;
                break;
            default:
                printf("sort: illegal option %c\n", c);
                argc = 1;
                rc = -1;
                break;
        }
    if (argc)
        printf("Usage: sort -nr \n");
    else if ((nlines = readlines(lineptr, LINES)) > 0) {
     if (option & NUMERIC)
    myqsort((void **) lineptr, 0, nlines - 1, (int (*)(void *, void *)) numcmp);
else
    myqsort((void **) lineptr, 0, nlines - 1, (int (*)(void *, void *)) mystrcmp);
writelines(lineptr, nlines, option & DECR);
    } else {
        printf("input too big to sort \n");
        rc = -1;
    }
    return rc;
}
