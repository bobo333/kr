/*
    htoi convert hexadecimal to integer value
*/
#include <stdio.h>
#include <stdlib.h>

int nextdigit(int cursum, char digit);

int main() {

    int sum, c;
    sum = 0;

    // handle leading 0x
    c = getchar();
    if (c == '0') {
        if ((c = getchar()) != 'x') {
            printf("expected x, got %c\n", c);
            return 1;
        }
    } else {
        sum = nextdigit(sum, c);
    }

    while ((c = getchar()) != '\n' && c != EOF)
        sum = nextdigit(sum, c);

    printf("%d\n", sum);

    return 0;
}

int nextdigit(int cursum, char digit) {
    cursum = cursum * 16;

    if (digit <= 'f' && digit >= 'a')
        cursum = cursum + digit - 'a' + 10;
    else if (digit <= 'F' && digit >= 'A')
        cursum = cursum + digit - 'A' + 10;
    else if (digit <= '9' && digit >= '0')
        cursum = cursum + digit - '0';
    else {
        printf("invalid character: %c\n", digit);
        exit(1);
    }

    return cursum;
}
