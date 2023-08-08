#include "alloc.h"

#include <stdio.h>

#define ALLOCSIZE 1000    /* size of available space */
static char allocbuf[ALLOCSIZE];    /* storage for alloc */
static char *allocp = allocbuf;        /* next free position */

char *alloc(int n)    /* return pointer to n characters */
{
    if (allocbuf + ALLOCSIZE - allocp >= n) {
        allocp += n;
        return allocp - n;
    } else
        return NULL;
}
