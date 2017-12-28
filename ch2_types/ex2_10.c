/*
lower with conditional expression instead of if else
*/
#include <stdio.h>

void lower(char str[]);

int main() {

    char str[] = "haHA";
    lower(str);

    printf("%s\n", str);

    return 0;
}

void lower(char str[]) {
    int i;
    char c;

    for (i = 0; str[i] != '\0'; i++) {
        c = str[i];
        str[i] = (c >= 'A' && c <= 'Z') ? 'a' + c - 'A' : c; 
    }
}
