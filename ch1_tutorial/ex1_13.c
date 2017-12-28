/*
    Histogram of input word lengths
    Limited to words of size 20
    Treats punctuation as the same as a character
*/

#include <stdio.h>

#define IN 1
#define OUT 0


int main() {

    int c, i, j, state, size;
    int counts[20];     // will handle max word size of 20 chars

    // initialize values
    size = 0;
    state = OUT;

    for (i = 0; i < 20; i++)
        counts[i] = 0;

    // count sizes
    while((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (size > 0)
                ++counts[size-1];

            // reset state and counter
            state = OUT;
            size = 0;
        } else {
            state = IN;
            ++size;
        }
    }

    // print histogram
    for (i = 0; i < 20; i++) {
        printf("%d\t", i + 1);
        j = 0;
        while (j < counts[i]){
            putchar('x');
            ++j;
        }
        putchar('\n');
    }

    return 0;
}