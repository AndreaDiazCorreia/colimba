#include <stdio.h>
#include <stdlib.h>

/*1.8 Correction*/
  int main()
  {
     int c, blanks = 0, tabs = 0, nl = 0;

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
