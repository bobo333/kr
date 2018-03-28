/* getfloat with pointers */
#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100


int getch(void);
void ungetch(int);
int getfloat(double *);

int bufp = 0;
char buf[BUFSIZE];

int main() {

    double floatarray[50];
    int i, count, res;

    for (count = 0; (res = getfloat(&floatarray[count])) != EOF; count++)
        ;

    for (i = 0; i < count; i++)
        printf("%f ", floatarray[i]);
    printf("\n");

    return 0;
}


int getfloat(double *pn) {
    int c, sign;
    double power;

    while (isspace(c = getch())) // skip white space
        ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c); // it's not a number
        return 0;
    }

    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        c = getch();
    }
    for (*pn = 0.0; isdigit(c); c = getch())
        *pn = 10.0 * *pn + (c - '0');

    if (c == '.') {
        for (power = 1.0; isdigit((c = getch())); ) {
            *pn = 10.0 * *pn + (c - '0');
            power *= 10.0;
        }
        *pn /= power;
    }

    *pn = *pn * sign;
    if (c != EOF)
        ungetch(c); // put back char we went past to find end of number
    return c;
}



// get a possibly pushed back character
int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}


// push character back to "input" buffer
void ungetch(int c) {
    if (bufp > BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
