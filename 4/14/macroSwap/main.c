#include <stdio.h>
#include <stdlib.h>

/*4.14*/
#define swap(t, x, y) { t* _x_ptr = &(x); \
                        t* _y_ptr = &(y); \
                        t _temp = *_x_ptr; \
                        *_x_ptr = *_y_ptr; \
                        *_y_ptr = _temp; }

int main(void) {
    char x, y;
    x = 'a';
    y = 'b';
    printf("x= %c \t y= %c\n", x, y);
    swap(char, x, y);
    printf("x=%c \t y=%c\n", x, y);
    return 0;
}
