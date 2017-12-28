/*
set specified right-most bits of a given number with the right-most
bits of another given number
*/
#include <stdio.h>

unsigned setbits(unsigned x, unsigned p, unsigned n, unsigned y);

int main() {
    unsigned res;

    res = setbits(91u, 4u, 3u, 6u);
    printf("res: %u\n", res);

    return 0;
}

unsigned setbits(unsigned x, unsigned p, unsigned n, unsigned y) {
    unsigned mask;

    // get mask for setting p -> p-n bits to 0
    // is a mask of 1s except 0s in p -> p-n
    mask = ~0;
    mask = mask << n;
    mask = ~mask;
    mask = mask << (p - n);
    mask = ~mask;

    // set n bits of x starting at p to all 0
    x = x & mask;

    // get right-most n bits of y
    // is all 0s except 1s in right-most n slots
    mask = ~0;
    mask = mask << n;
    mask = ~mask;

    y = y & mask;

    // adjust to proper position by padding with 0s on right
    y = y << (p - n);

    // recombine together
    // since x has all 0s in the target slots...
    return x | y;
}
