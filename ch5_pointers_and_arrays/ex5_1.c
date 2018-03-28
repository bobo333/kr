/* better getint */
#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100


int getch(void);
void ungetch(int);
int getint(int *);

int bufp = 0;
char buf[BUFSIZE];

int main() {

    int intarray[50];
    int i, count, res;

    for (count = 0; (res = getint(&intarray[count])) != EOF; count++)
        ;

    for (i = 0; i < count; i++)
        printf("%d ", intarray[i]);
    printf("\n");

    return 0;
}


int getint(int *pn) {
    int c, sign, signchar;

    while (isspace(c = getch())) // skip white space
        ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c); // it's not a number
        return 0;
    }

    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        signchar = c;
        c = getch();
        if (!isdigit(c)) {
            ungetch(c);
            ungetch(signchar);
            return signchar; // not a number, handler needs to do something here
        }
    }
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
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
