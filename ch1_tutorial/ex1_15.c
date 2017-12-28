/*
    Fahrenheit Celsius conversion using a function
*/

#include <stdio.h>


float ftoc(int fahr);

int main() {
    int f, lower, upper, step;
    float c;

    lower = 0;
    upper = 300;
    step = 20;

    printf("Fahrenheit\tCelsius\n");
    for (f = lower; f <= upper; f = f + 20)
        printf("%d\t\t%2.1f\n", f, ftoc(f));

    return 0;
}

float ftoc(int fahr) {
    return (5.0/9.0) * (fahr - 32);
}
