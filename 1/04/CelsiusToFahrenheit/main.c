#include <stdio.h>
#include <stdlib.h>

/*1.4*/
int main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 100;
    step = 10;

    printf("Cesius\t\tFahrenheit\n");

    celsius = lower;
    while (celsius <= upper){
        fahr = (celsius * 9.0/5.0)+32.0;
        printf("%6.1f\t\t%3.0f\n", celsius, fahr);
        celsius = celsius + step;
    }
    return 0;
}
