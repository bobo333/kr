/*
    print lines longer than 80 chars
    doesn't check for size limit!
*/

#include <stdio.h>

int getlinesteve(char s[]);

int main() {
    int MINSIZE = 81;
    char line[1000];
    int len;

    while ((len = getlinesteve(line)) != 0) {
        if (len > MINSIZE)
            printf("%s", line);
    }

    return 0;
}


int getlinesteve(char s[]) {
    int len, c;

    for (len = 0; (c = getchar()) != EOF && c != '\n'; ++len)
        s[len] = c;
    if (c == '\n') {
        s[len] = c;
        ++len;
    }
    s[len] = '\0';

    return len;
}
