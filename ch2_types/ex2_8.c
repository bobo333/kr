/*
rotate n bits to the right
*/
#include <stdio.h>

int rightrot(int x, int n);

int main() {

    int res;

    res = rightrot(13, 2);
    printf("res: %d\n", res);

    return 0;
}

int rightrot(int x, int n) {
    unsigned mask;
    int right, y, len;

    // do mod with length of bit string first to handle wrap around
    y = x;
    for (len = 0; y > 0; len++)
        y = y >> 1;

    n = n % len;

    // get right-most n bits
    mask = ~0;
    mask = mask << n;
    mask = ~mask;

    right = x & mask;

    // move original n bits to the right
    x = x >> n;

    // move old right-most len-n bits to the left
    right = right << (len - n);

    // | them together
    return x | right;
}
