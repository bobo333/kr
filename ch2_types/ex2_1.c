/*
    Shows max size of various types
*/
#include <float.h>
#include <limits.h>
#include <stdio.h>

int main() {
    // char
    printf("char is between %d and %d\n", CHAR_MIN, CHAR_MAX);
    printf("\n");

    // int
    printf("signed int is between %d and %d\n", INT_MIN, INT_MAX);
    printf("unsigned int is between %u and %u\n", 0, UINT_MAX-1);
    printf("\n");

    printf("signed short (int) is between %d and %d\n", SHRT_MIN, SHRT_MAX);
    printf("unsigned short (int) is between %u and %u\n", 0, USHRT_MAX);
    printf("\n");

    printf("signed long (int) is between %ld and %ld\n", LONG_MIN, LONG_MAX);
    printf("unsigned long (int) is between %lu and %lu\n", (long) 0, ULONG_MAX);
    printf("\n");

    printf("signed long long (int) is between %lld and %lld\n", LLONG_MIN, LLONG_MAX);
    printf("unsigned long long (int) is between %llu and %llu\n", (long long) 0, ULLONG_MAX);
    printf("\n");

    printf("calculated max unsigned int %u\n", getmaxint());

    // float
    // long, short
    // double
    // long, short

}

// strangely returns one larger than expected 4294967295
// whereas UINT_MAX is 4294967294
int getmaxint() {
    unsigned int i, j;
    i = 1;
    j = 0;
    for (; i != 0; i++, j++)
        ;
    return j;
}
