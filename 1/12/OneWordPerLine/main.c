#include <stdio.h>
#include <stdlib.h>
#define IN 1
#define OUT 0

/*1.12*/
int main()
{
    int c;
    int state = OUT;

    while((c = getchar()) != EOF){
        if (c == ' '|| c == '\n'|| c == '\t'){
            if(state == IN){
                putchar('\n');
                state= OUT;
            }
        } else {
            putchar(c);
            state = IN;
        }
    }
    return 0;
}
