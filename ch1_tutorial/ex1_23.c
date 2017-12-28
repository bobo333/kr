/*
    De-comment a C program
*/

#include <stdio.h>

#define INCOMMENT 1
#define INCODE 2
#define SLASH '/'
#define STAR '*'

// start copying characters
// find start comment
// stop copying until end of comment
// start copying characters again

int main() {

    int state, curchar, nextchar;

    state = INCODE;

    while ((curchar = getchar()) != EOF) {
        if (state == INCODE) {
            if (curchar != SLASH)
                putchar(curchar);
            else
                if ((nextchar = getchar()) == SLASH) {
                    while ((nextchar = getchar()) != '\n')
                        ;
                }
                else if (nextchar == STAR)
                    state = INCOMMENT;
                else {
                    putchar(curchar);
                    putchar(nextchar);
                }
        } else if (state == INCOMMENT) {
            while ((curchar = getchar()) != STAR)
                ;

            if ((nextchar = getchar()) == SLASH)
                    state = INCODE;
        }
    }

    return 0;
}
