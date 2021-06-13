#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int arg1;
    int arg2;
    char operator[2];
    char operation;

    // determine if string was provided as arg
    char *equation;
    if (argc > 1) {
        equation = argv[1];
        sscanf(equation, "%d%1s%d", &arg1, operator, &arg2);
    } else {
        scanf("%d%1s%d", &arg1, operator, &arg2);
    }

    operation = operator[0];

    printf("equation: %s\n", equation);
    printf("arg1: %d\narg2: %d\noperation: %c\n", arg1, arg2, operation);

    int result;
    switch(operation) {
        case '+':
            result = arg1 + arg2;
            break;
        case '-':
            result = arg1 - arg2;
            break;
        case 'x':
        case '*':
            result = arg1 * arg2;
            break;
        case '/':
            result = arg1 / arg2;
            break;
        default:
            return 1;
    }

    printf("%d%c%d=%d\n", arg1, operation, arg2, result);
}
