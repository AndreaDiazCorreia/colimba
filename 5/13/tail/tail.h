#ifndef TAIL_H
#define TAIL_H

#define DEFLINES 10 /* default # of lines to print */
#define LINES    100    /* maximum # of lines to print */
#define MAXLEN    100    /* maximum length of an input line */

void error(char *);
int mgetline(char *, int);

#endif
