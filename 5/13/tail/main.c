#include <stdio.h>
#include <stdlib.h>
#include "tail.h"

/*5.13*/
int main(int argc, char *argv[]) {
    char *p;
    char *buf;    /* pointer to the large buffer */
    char *bufend;    /* end of the large buffer */

    char line[MAXLEN];
    char *lineptr[LINES];    /* pointer to lines read */

    int first, i, last, len, n, nlines;

    if (argc == 1)
        n = DEFLINES;
    else if (argc == 2 && (*++argv)[0] == '-')
        n = atoi(argv[0] + 1);
    else
        error("Usage: tail [-n]");

    if (n < 1 || n > LINES)
        n = LINES;

    for (i = 0; i < LINES; i++)
        lineptr[i] = NULL;

    if ((p = buf = malloc(LINES * MAXLEN)) == NULL)
        error("tail: cannot allocate buf");
    bufend = buf + LINES + MAXLEN;

    last = 0;
    nlines = 0;

    while ((len = mgetline(line, MAXLEN)) > 0) {
        if (p + len + 1 >= bufend)
            p = buf;
        lineptr[last] = p;

        strcpy(lineptr[last], line);
        if (++last >= LINES)
            last = 0;

        p += len + 1;
        nlines++;
    }

    if (n > nlines)
        n = nlines;

    first = last - n;

    if (first < 0)
        first += LINES;

    for (i = first; n-- > 0; i = (i + 1) % LINES)
        printf("%s", lineptr[i]);

    free(buf);

    return 0;
}
