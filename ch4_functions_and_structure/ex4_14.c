/* macro to reverse 2 arguments of type t */
#include <stdio.h>

#define swap(t, x, y)  { t _z; \
                         _z = y; \
                         y = x; \
                         x = _z;}


int subtract(int, int);

int main() {

    int x, y;
    
    x = 5, y = 3;
    printf("x: %d, y: %d\n", x, y);

    swap(int, x, y);
    printf("x: %d, y: %d\n", x, y);


    return 0;
}

int subtract(int x, int y) {
    return x - y;
}
