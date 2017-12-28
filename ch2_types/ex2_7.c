/*
invert n bits of x starting at p
*/
#include <stdio.h>

int invert(int x, int p, int n);

int main() {

    int res;

    res = invert(471, 6, 3);
    printf("res: %d\n", res);

    return 0;
}


int invert(int x, int p, int n) {
    unsigned mask;

    // get mask of all 0s except for 1s in p -> p-n position
    mask = ~0;
    mask = mask << n;
    mask = ~mask;
    mask = mask << (p-n);

    // ^ with 1s flips bits, ^ with 0s keeps bits the same
    return x ^ mask;
}
