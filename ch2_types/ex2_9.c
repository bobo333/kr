/*
Faster bitcount, count # of 1 bits in number
*/
#include <stdio.h>

int bitcount(unsigned x);

int main() {

    int res;

    res = bitcount(0);
    printf("res: %d\n", res);

    return 0;
}

int bitcount(unsigned x) {
    int count;

    if (x == 0)
        return 0;

    // x &= (x - 1) deletes right-most 1 bit of x
    for (count = 1; (x &= (x - 1)) > 0; count++)
        ;

    return count;
}
