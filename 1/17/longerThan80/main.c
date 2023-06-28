#include <stdio.h>
#define MAXLINE 1000
#define MINLENGTH 80

/*1.17*/
int getline(char line[], int maxline);

int main()
{
    char line[MAXLINE];
    int len;

    while ((len = getline(line, MAXLINE)) != 0)
    {
        if (len > MINLENGTH)
        {
            printf("%s", line);
        }
    }

    return 0;
}

int getline(char line[], int maxline)
{
    int c, i;

    for (i = 0; i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        line[i] = c;
    }

    if (c == '\n')
    {
        line[i] = c;
        ++i;
    }

    line[i] = '\0';

    return i;
}
