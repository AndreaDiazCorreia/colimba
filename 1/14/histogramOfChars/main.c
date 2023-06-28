#include <stdio.h>
#include <stdlib.h>
#define MAX 128

/*1.14*/
int main()
{
    int c;
    int freq[MAX] = {0};
    int i, j;

    while ((c = getchar())!= EOF){
        if(c < MAX){
            ++freq[c];
        }
    }

    printf("histogram of the frequencies of different characters\n");

    for (i = 0; i<MAX; ++i){
        if(freq[i] > 0){
            printf("%c: ", i);
            for (j= 0; j<freq[i]; ++j){
                printf("#");
            }
            printf("\n");
        }
    }
    return 0;
}
