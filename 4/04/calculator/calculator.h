#ifndef CALCULATOR_H
#define CALCULATOR_H

#define MAXOP 100   /* max size of operand or operator */
#define NUMBER '0'  /* signal that a number was found */
#define MODULO '%'  /* signal that the operator is modulo */

void push(double);
double pop(void);
void peek(void);
void duplicate(void);
void swap(void);
void clear(void);
int getop(char []);

#endif // CALCULATOR_H
