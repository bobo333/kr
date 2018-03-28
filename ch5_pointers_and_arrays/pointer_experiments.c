/* pointers vs arrays */
#include <stdio.h>


int main() {
    int intarray[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *ip;

    ip = intarray;
    printf("when assigned to array name: %d\n", *ip);

    ip = &intarray[0];
    printf("when assigned to address of first element: %d\n", *ip);

    printf("incrementing pointer by one %d\n", *(ip + 1));
    printf("incrementing array name by one and dereferencing %d\n", *(intarray + 1));

    ip = intarray+4;
    printf("pointing to array name + 4: %d\n", *ip);

    ip = &intarray[4];
    printf("pointing to address of 4th element of array: %d\n", *ip);

    printf("decrementing by 2: %d\n", *(ip - 2));

    return 0;
}
