/* convert number to string in various bases
    prints an extra leading 0 if the number is only 1 place,
    can't figure out how to fix it, but it does handle the max int
    min_int must be min_int + 1 because it converts number to positive
 */
#include <stdio.h>
#include <limits.h>

void itob(int n, char s[], int base);
void runtest(int x, int b);

int main() {
    runtest(50, 10);
    runtest(50, 8);
    runtest(50, 16);
    runtest(50, 2);
    runtest(60, 16);
    runtest(0, 5);
    runtest(-10, 2);
    runtest(-10, 8);
    runtest(-10, 10);
    runtest(-10, 16);
    runtest(10, 16);
    runtest(10, 10);
    runtest(5, 10);
    runtest(INT_MIN + 1, 16);
    runtest(INT_MAX, 16);

    return 0;
}

void itob(int n, char s[], int base) {

    int i, divisor, place_value, place_number;
    i = 0;
    place_number = 2;

    if (n < 0) {
        n *= -1;
        s[i++] = '-';
    }

    for (divisor = base; (n / divisor) >= base; divisor *= base, place_number++)
        ;

    do {
        place_value = n / divisor;
        
        if (place_value >= 10)
            s[i++] = place_value - 10 + 'A';
        else
            s[i++] = place_value + '0';
        
        n %= divisor;
        divisor /= base;
        place_number--;
    } while (place_number > 0);

    s[i] = '\0';
}

void runtest(int x, int base) {
    char s[50];
    itob(x, s, base);
    printf("%3d is %15s in base %d\n", x, s, base);
}
