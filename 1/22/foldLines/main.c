#include <stdio.h>
#include <stdlib.h>

#define MAX 80
#define COLUMN 40

 /*1.22*/

void foldLine(char line[], int foldColumn);

int main()
{
    char line[MAX];

    printf("Ingrese una línea de texto:\n");
    fgets(line, MAX, stdin);

    foldLine(line, COLUMN);

    printf("Línea plegada:\n%s\n", line);
    return 0;
}

void foldLine(char line[], int foldColumn)
{
    int lastNonBlank = -1;
    int i;

    for (i = 0; i < foldColumn; i++)
    {
        if (line[i] != ' ' && line[i] != '\t')
        {
            lastNonBlank = i;
        }
    }

    if (lastNonBlank == -1)
    {
        return;
    }

    if (lastNonBlank >= foldColumn - 1)
    {
        return;
    }

    int lineLength = strlen(line);
    for (i = lineLength - 1; i > lastNonBlank; i--)
    {
        if (i >= foldColumn && line[i] == ' ')
        {
            line[i] = '\n';
        }
    }
}
