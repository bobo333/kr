/* strend with pointers */
#include <stdio.h>

int strend(char *, char *);
void teststrend(char *, char *, int);


int main() {

    teststrend("hi there", "there", 1);
    teststrend("hi there", "where", 0);
    teststrend("hi there", "there ", 0);
    teststrend("ere", "there", 0);
    teststrend("ere", "", 1);  
    teststrend("", "ere", 0);    
    teststrend("", "", 1);

    return 0;
}


int strend(char *corpus, char *target) {

    int toffset, coffset;

    for (toffset = 0; *(target + toffset) != '\0'; toffset++)
        ;

    for (coffset = 0; *(corpus + coffset) != '\0'; coffset++)
        ;

    if (toffset > coffset)
        return 0;   // target longer than corpus

    for (; toffset >= 0; toffset--, coffset--)
        if (*(corpus + coffset) != *(target + toffset))
            return 0;

    return 1;
}


void teststrend(char *corpus, char *target, int expected) {
    int res = strend(corpus, target);

    if (res != expected)
        printf("\nFAIL expected %d got %d\n"
               "corpus: %s\ntarget: %s\n\n", expected, res, corpus, target);
    else
        printf("ok\n");

}
