#include <ctype.h>
#include <stdio.h>

#define BUFSIZE 100

char letter_buffer[BUFSIZE];
int lc = 0;


int getword(char *target, int max_len) {
    char cur;
    char *t = target;

    while (!isalpha(cur = getchar()) && cur != EOF) // skip spaces
        ;

    if (cur == EOF)   // end of input
        return cur;
    else
        *t++ = cur;

    while (--max_len > 0 && isalpha(cur = getchar()))
        *t++ = cur;

    *t = '\0';
    return target[0];
}
