#include <stdio.h>
#include <string.h>
#include "calculator.h"

/*4.8*/

void do_math_operation(char s[]) {
    if (strcmp(s, "sin") == 0)
        push(sin(pop()));
    else if (strcmp(s, "cos") == 0)
        push(cos(pop()));
    else if (strcmp(s, "exp") == 0)
        push(exp(pop()));
    else if (strcmp(s, "pow") == 0) {
        double op2 = pop();
        push(pow(pop(), op2));
    } else
        printf("error: unknown math function %s\n", s);
}

void do_operator(char op) {
    double op2, op1;
    switch (op) {
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: division by zero\n");
            break;
        case '%':
            op2 = pop();
            if (op2 != 0.0)
                push(fmod(pop(), op2));
            else
                printf("error: division by zero\n");
            break;
        case '?':
            op2 = pop();
            printf("\t%.8g\n", op2);
            push(op2);
            break;
        default:
            printf("error: unknown operator %c\n", op);
            break;
    }
}

int main(void) {
    int type;
    double op2, op1;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case NAME:
                mathfnc(s);
                break;
            case '+':
            case '*':
            case '-':
            case '/':
            case '%':
            case '?':
                do_operator(type);
                break;
            case 'c':
                clearsp();
                break;
            case 'd':
                push(peek());
                break;
            case 's':
                swap();
                break;
            case '\n':
                printf("Result: %.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                ungets(s);
                break;
        }
    }
    return 0;
}
