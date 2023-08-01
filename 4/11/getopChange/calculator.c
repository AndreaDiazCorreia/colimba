#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include "calculator.h"

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];
char lastChar = ' ';

void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

double pop(void) {
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

void clearsp(void) {
    sp = 0;
}

int getop(char s[]) {
    int c, i;
    static int lastc = 0;

    if (lastc == 0)
        c = getch();
    else {
        c = lastc;
        lastc = 0;
    }

    while ((s[0] = c) == ' ' || c == '\t')
        c = getch();

    s[1] = '\0';

    if (!isdigit(c) && c != '.')
        return c;

    i = 0;
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()));
    if (c == '.')
        while (isdigit(s[++i] = c = getch()));
    s[i] = '\0';

    if (c != EOF)
        lastc = c;

    return NUMBER;
}

double peek(void) {
    if (sp > 0)
        return val[sp - 1];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}
void swap(void) {
    if (sp > 1) {
        double temp = val[sp - 1];
        val[sp - 1] = val[sp - 2];
        val[sp - 2] = temp;
    } else {
        printf("error: not enough elements in the stack to perform swap\n");
    }
}

int getch(void) {
    int c = (lastChar != ' ') ? lastChar : getchar();
    lastChar = ' ';
    return c;
}

void ungetch(int c) {
    if (lastChar != ' ')
        printf("ungetch: already a character in pushback\n");
    else
        lastChar = c;
}

void ungets(const char s[]) {
    int i = 0;
    while (s[i] != '\0') {
        ungetch(s[i]);
        i++;
    }
}

void mathfnc(char s[]) {
    double op1, op2;
    if (strcmp(s, "sin") == 0 || strcmp(s, "cos") == 0 || strcmp(s, "exp") == 0 || strcmp(s, "pow") == 0) {
        op2 = pop();
        if (strcmp(s, "sin") == 0)
            push(sin(op2));
        else if (strcmp(s, "cos") == 0)
            push(cos(op2));
        else if (strcmp(s, "exp") == 0)
            push(exp(op2));
        else if (strcmp(s, "pow") == 0) {
            op1 = pop();
            push(pow(op1, op2));
        }
    } else {
        printf("error: %s is not supported\n", s);
    }
}
