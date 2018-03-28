/* polish notation calculator from command line */
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h> // for atof()

#define MAXOP 100 // max size of operand or operator
#define NUMBER '0' // signal that a number was found
#define MAXVAL 100 // maximum depth of call stack
#define BUFSIZE 100

char buf[BUFSIZE]; // buffer for ungetch
int bufp = 0;   // next free position in buf
int sp = 0; // next free stack position
double val[MAXVAL]; // value stack

int getop(char [], char *);
void push(double);
double pop(void);
void showtop(void);
void duplicate(void);
void swap(void);
void clear(void);

/* reverse polish calculator */
int main(int argc, char * argv[]) {
    int type, i;
    double op2;
    char s[MAXOP];

    for (i = 1; --argc; i++) {
        type = getop(s, argv[i]);

        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '%':
                op2 = pop();
                if (op2 != 0){
                    double dividend = pop();
                    printf("warning: casting to int for modulus operation\n%f to %d and %f to %d\n", 
                           dividend, (int) dividend, op2, (int) op2);
                    push( (double) ((int) dividend % (int) op2)); // no modulus for floats
                }
                else
                    printf("error: zero divosor\n");
                break;
            case 's':
                push(sin(pop()));
                break;
            case 'd':   // duplicate top element
                duplicate();
                break;
            case 'w':   // swap top 2 elements of stack
                swap();
                break;
            case 'c':   // swap top 2 elements of stack
                clear();
                break;
            case '\n':
                showtop();
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    showtop();
    return 0;
}


/* clear the stack */
void clear(void) {
    sp = 0;
}


/* swap top 2 elements of stack */
void swap(void) {
    if (sp > 1) {
        double cur = val[sp-1];
        val[sp - 1] = val[sp - 2];
        val[sp - 2] = cur;
    } else 
        printf("stack has less than 2 elements\n");
}


/* duplicate top element of stack */
void duplicate(void) {
    if (sp > 0) {
        double cur = val[sp-1];
        val[sp++] = cur;
    } else 
        printf("stack empty\n");
}


/* show top of stack */
void showtop(void) {
    if (sp > 0)
        printf("top of stack: %f\n", val[sp-1]);
    else
        printf("stack empty\n");
}


/* push: push f onto the value stack */
void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}


/* pop: pop and return top value from stack */
double pop(void) {
    if (sp > 0) {
        return val[--sp];
    } else {
        printf("error: stack empty\n");
        return 0.0;
    }
}


/* getop: get next operator or numeric operand */
int getop(char s[], char * arg) {
    int i, c, peek;

    // skip white space
    while ((s[0] = c = *arg++) == ' ' || c == '\t')
        ;
    s[1] = '\0';

    // handle negative numbers
    i = 0;
    if (c == '-') {
        if (isdigit(peek = *++arg)) {
            s[++i] = peek;
            c = peek;
        } else {
            arg--;
            return c;
        }
    } else if (!isdigit(c) && c != '.')
        return c;   // c is not a number

    if (isdigit(c)) // collect integer part
        while (isdigit(s[++i] = c = *arg++)) // also grabs the decimal point!
            ;

    if (c == '.') // collect fraction part
        while (isdigit(s[++i] = c = *arg++))
            ;

    s[i] = '\0';

    return NUMBER;
}
