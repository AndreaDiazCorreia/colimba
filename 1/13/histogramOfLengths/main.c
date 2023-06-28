#include <stdio.h>
#include <stdlib.h>
#define MAX 20

/*1.13*/
int main()
{
    int c;
    int wl = 0;
    int wla[MAX + 1] = {0};
    int i, j;

    while ((c = getchar()) != EOF){
        if (c == ' ' || c == '\n' || c == '\t'){
            if (wl > 0 && wl <= MAX){
                ++wla[wl];
            }
            wl = 0;
        } else {
            ++wl;
        }
    }

    printf("histogram of the lengths of words\n");
    for (i = 1; i <= MAX; ++i){
        printf("%2d: ", i);
        for (j = 0; j < wla[i]; ++j){
            printf("#");
        }
        printf("\n");
    }
    return 0;
}
