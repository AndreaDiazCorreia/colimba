#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*2.1*/
int main()
{
   int char_min, char_max;
   int uchar_min, uchar_max;

   long int_min, int_max;
   long uint_min, uint_max;


   char_min = (char)(1 << (sizeof(char) * 8 - 1));
   char_max = ((char)(~0 & ~char_min));

   printf("char MIN is %d, char MAX is %d\n", char_min, char_max);
   printf("CHAR_MIN is %d, CHAR_MAX is %d\n", CHAR_MIN, CHAR_MAX);

   uchar_min = (unsigned char)0;
   uchar_max = (unsigned char)~0;

   printf("unsigned char MIN is %d, unsigned char MAX is %d\n", uchar_min, uchar_max);
   printf("UCHAR_MIN is %d, UCHAR_MAX is %d\n", 0, UCHAR_MAX);

   int_min = (int)(1 << (sizeof(int) * 8 - 1));
   int_max = ((int)(~0 & ~int_min));

   printf("int MIN is %lld, int MAX is %lld\n", int_min, int_max);
   printf("INT_MIN is %d, INT_MAX is %d\n", INT_MIN, INT_MAX);

   uint_min = (unsigned int)0;
   uint_max = (unsigned int)~0;

   printf("unsigned int MIN is %lld, unsigned int MAX is %lld\n", uint_min, uint_max);
   printf("UINT_MIN is %u, UINT_MAX is %u\n", 0, UINT_MAX);

   return 0;
}
