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
    int i, c;
    int lastChar;

    while ((s[0] = c = getch()) == ' ' || c == '\t');


    if (islower(c)) {
        i = 0;
        while (islower(s[++i] = c = getch()));
        s[i] = '\0';

        if (c != EOF)
            ungetch(c);

        if (strlen(s) > 1)
            return NAME;
        else
            return s[0];
    }


    if (!isdigit(c) && c != '.' && c != '-') {
        lastChar = c;
        return c;
    }

    if (c == '-') {
        lastChar = c;
        if (isdigit(c = getch()) || c == '.')
            s[++i] = c;
        else {
            if (c != EOF)
                ungetch(c);
            return '-';
        }
    }

    i = 0;
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()));

    if (c == '.')
        while (isdigit(s[++i] = c = getch()));

    s[i] = '\0';
    if (c != EOF)
        ungetch(c);

    lastChar = c;
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
