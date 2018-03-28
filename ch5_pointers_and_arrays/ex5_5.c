/* strncpy and strncmp with pointers, note: does not handle problem where 
accepter is too short, apparently the stdlib versions don't do this either */
#include <stdio.h>

int strncmp_custom(char *, char *, int);
void strncpy_custom(char *, char *, int);
void teststrncmp_custom(char *, char *, int, int);


int main() {

    teststrncmp_custom("hi there", "hi", 2, 1);
    teststrncmp_custom("hi there", "hi", 50, 1);
    teststrncmp_custom("hi there", "hiz", 2, 1);
    teststrncmp_custom("hi there", "hiz", 3, 0);
    teststrncmp_custom("hi there", "", 3, 1);
    teststrncmp_custom("hi there", "hi after not the same", 3, 1);
    teststrncmp_custom("hi there", "diff", 0, 1);
    teststrncmp_custom("hi", "hi there", 2, 1);


    char start[] = "hello";
    char dest[20];


    strncpy_custom(dest, start, 3);
    printf("%s\n", dest);

    strncpy_custom(dest, start, 9);
    printf("%s\n", dest);

    return 0;
}


int strncmp_custom(char * str1, char * str2, int n) {
    int i;
    char c1, c2;

    for (i = 0; i < n && (c1 = *(str1 + i)) != '\0' && (c2 = *(str2 + i)) != '\0'; i++)
        if (c1 != c2)
            return 0;

    return 1;
}


void strncpy_custom(char * destination, char * source, int n) {
    int i;
    char c;

    for (i = 0; (c = *(source + i)) != '\0' && i < n; i++)
        *(destination + i) = c;

    *(destination + i) = '\0';
}


void teststrncmp_custom(char *str1, char *str2, int n, int expected) {
    int res;

    res = strncmp_custom(str1, str2, n);

    if (res != expected)
        printf("\nFAIL expected %d got %d\n"
               "str1: %s\n"
               "str2: %s\n"
               "n: %d\n\n", expected, res, str1, str2, n);
    else
        printf("ok\n");
}
