#include <stdio.h>
#include "calculator.h"

/*5.10*/

int main(int argc, char *argv[]) {
    int i;
    double result;

    for (i = 1; i < argc; i++) {
        switch (getop(argv[i])) {
        case NUMBER:
            push(atof(argv[i]));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '-':
            push(pop() - pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '/':
            push(pop() / pop());
            break;
        case MODULO:
            push((int)pop() % (int)pop());
            break;
        default:
            printf("error: unknown command %s\n", argv[i]);
            break;
        }
    }

    result = pop();
    printf("Result: %.8g\n", result);

    return 0;
}
