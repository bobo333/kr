/* pointer version of strcat */
#include <stdio.h>


void strcatpt(char *, char *);

int main() {
    int i;

    char s[30];
    char start[] = "hello to you";
    char t[] = " and to you too!";

    /* there's probably a better way to initialize this, but
        the array has to be long enough to hold both strings */
    for (i = 0; start[i] != '\0'; i++)
        s[i] = start[i];

    printf("s before: %s\n", s);
    printf("t before: %s\n", t);

    strcatpt(s, t);

    printf("s after: %s\n", s);
    printf("t after: %s\n", t);

    return 0;
}


void strcatpt(char *s, char *t) {
    // get to end of s
    for (; *s != '\0'; s++) // avoids going past the terminating char
        ;

    while ((*s++ = *t++))   // parens not necessary, but suggested by compiler
        ;
}
