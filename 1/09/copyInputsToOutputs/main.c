#include <stdio.h>
#include <stdlib.h>

/*1.9*/
main()
{
    int c;

    while ((c = getchar()) != EOF){
        if (c == ' '){
            putchar(c);
            while ((c = getchar()) == ' ')
                ;
        }
        if(c != ' ')
            putchar(c);
    }
    return 0;
}
