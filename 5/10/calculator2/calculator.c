#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "calculator.h"

#define MAXVAL 100  /* maximum depth of val stack */

int sp = 0;         /* next free stack position */
double val[MAXVAL]; /* value stack */

/* push: push f onto value stack */
void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void) {
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

/* peek: print the top element of the stack without popping */
void peek(void) {
    if (sp > 0)
        printf("Top element: %.8g\n", val[sp - 1]);
    else
        printf("error: stack empty\n");
}

/* duplicate: duplicate the top element of the stack */
void duplicate(void) {
    if (sp > 0) {
        double top = val[sp - 1];
        push(top);
    } else {
        printf("error: stack empty\n");
    }
}

/* swap: swap the top two elements of the stack */
void swap(void) {
    if (sp > 1) {
        double top = pop();
        double second = pop();
        push(top);
        push(second);
    } else {
        printf("error: insufficient elements in the stack\n");
    }
}

/* clear: clear the stack */
void clear(void) {
    sp = 0;
}

/* getop: get next operator or numeric operand */
int getop(char s[]) {
    int i, c;

    while ((s[0] = c = getchar()) == ' ' || c == '\t')
        ;
    s[1] = '\0';

    if ((!isdigit(c) && c != '.' && c != '-' && c != '+') ||
        (c == '-' && !isdigit(s[1]) && s[1] != '.')) {
        return c;
    }

    i = 0;
    if (c == '-' || c == '+') {
        if (isdigit(s[++i] = c = getchar()) || c == '.') {
            while (isdigit(s[++i] = c = getchar()))
                ;
        } else {
            ungetc(c, stdin);
            return s[0];
        }
    }

    if (isdigit(c))
        while (isdigit(s[++i] = c = getchar()))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = getchar()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetc(c, stdin);
    return NUMBER;
}
