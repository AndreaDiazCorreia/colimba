#ifndef CALCULATOR_H
#define CALCULATOR_H

#define MAXOP 100
#define NUMBER '0'
#define NAME 'n'
#define BUFSIZE 100
#define MAXVAL 100

void push(double);
double pop(void);
void clearsp(void);
int getop(char[]);
int getch(void);
void ungetch(int);
void mathfnc(char[]);
double peek(void);
void swap(void);

#include <math.h>

#endif
