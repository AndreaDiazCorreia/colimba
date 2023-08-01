#include <ctype.h>
#include <stdio.h>

#define MAXLINE 100

/*4.2*/

double atof(char s[]);
int mgetline(char line[], int lim);

int main(void) {
    char str[MAXLINE];
    double num;
    mgetline(str, MAXLINE);

    num = atof(str);
    printf("%f", num);

    return 0;
}

double atof(char s[]) {
    double val = 0.0;
    int sign = 1, expSign = 1;
    int i = 0, exp = 0;

    /*Skip blanks*/
    while (isspace(s[i]))
        i++;

    /* Determine the sign of the number*/
    if (s[i] == '-') {
        sign = -1;
        i++;
    } else if (s[i] == '+') {
        i++;
    }

    /* Obtain the integer part of the value*/
    for (; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');

    /* Obtaining the decimal part */
    if (s[i] == '.') {
        double pow10 = 1.0;
        i++;
        for (; isdigit(s[i]); i++) {
            val = 10.0 * val + (s[i] - '0');
            pow10 *= 10.0;
        }
        val /= pow10;
    }

    /* Obtain the exponent if it exists*/
    if (s[i] == 'e' || s[i] == 'E') {
        i++;
        if (s[i] == '-') {
            expSign = -1;
            i++;
        } else if (s[i] == '+') {
            i++;
        }

        for (; isdigit(s[i]); i++)
            exp = 10 * exp + (s[i] - '0');
    }

    /* Adjust the final value */
    if (exp != 0) {
        double pow10 = 1.0;
        while (exp > 0) {
            pow10 *= 10;
            exp--;
        }
        while (exp < 0) {
            pow10 /= 10;
            exp++;
        }
        val *= (expSign > 0) ? pow10 : 1.0 / pow10;
    }

    return sign * val;
}

int mgetline(char line[], int lim) {
    int i, c;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;

    if (c == '\n')
        line[i++] = c;

    line[i] = '\0';
    return i;
}
