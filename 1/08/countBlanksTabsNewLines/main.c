#include <stdio.h>
#include <stdlib.h>

/*1.8*/
int main()
{
    int c, blanks, tabs, nl;
    blanks = tabs = nl;

    while ((c = getchar()) != EOF) {
        if (c == ' ')
            ++blanks;
        else if (c == '\t')
            ++tabs;
        else if (c == '\n')
            ++nl;
    }

    printf ("Blanks: %d\n", blanks);
    printf ("Tabs: %d\n", tabs);
    printf ("Newlines: %d\n", nl);
    return 0;
}
