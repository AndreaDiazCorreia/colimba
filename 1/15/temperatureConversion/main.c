#include <stdio.h>
#include <stdlib.h>

/*1.15*/
float convertToFahr(float celsius){
    return (celsius * 9.0/5.0) + 32.0;
}
float convertToCelsius(float fahr){
    return (fahr - 32) * 5.0/9.0;
}
int main() {
    float temperature;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    printf("Celsius\tFahrenheit\n");
    for (temperature = lower; temperature <= upper; temperature += step) {
        float fahr = convertToFahr(temperature);
        printf("%6.1f\t%9.1f\n", temperature, fahr);
    }

    printf("\n");

    printf("Fahrenheit\tCelsius\n");
    for (temperature = lower; temperature <= upper; temperature += step) {
        float celsius = convertToCelsius(temperature);
        printf("%9.1f\t%6.1f\n", temperature, celsius);
    }

    return 0;
}
