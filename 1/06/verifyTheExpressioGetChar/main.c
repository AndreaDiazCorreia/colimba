#include <stdio.h>
#include <stdlib.h>

/*1.6*/
int main()
{
    int c;

    c= (getchar()!= EOF);

    printf("c: %d\n", c);
    return 0;
}
