/* string to double, with scientific notation */
#include <ctype.h>
#include <stdio.h>


double atof(char s[]);


int main() {
    double res;
    char input[] = "3.65e-2";

    res = atof(input);
    printf("%s is %f\n", input, res);

    char input2[] = "3.65e2";
    res = atof(input2);
    printf("%s is %f\n", input2, res);

    char input3[] = "-566.6509e23";
    res = atof(input3);
    printf("%s is %f\n", input3, res);

    return 0;
};


double atof(char s[]) {

    double val, power;
    int i, sign, exponent, negexp;

    for (i = 0; isspace(s[i]); i++) // skip white space
        ;

    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++; // move past sign

    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }

    exponent = 0;
    negexp = 0;

    if (s[i] == 'E' || s[i] == 'e') {
        i++;

        if (s[i] == '-') {
            negexp = 1;
            i++;
        }

        for (; isdigit(s[i]); i++) {
            exponent = exponent * 10 + (s[i] - '0');
        }
    }

    val =  sign * val / power;

    for (i = 0; i < exponent; i++) {
        if (negexp)
            val /= 10.0;
        else
            val *= 10.0;
    }

    return val;
}
