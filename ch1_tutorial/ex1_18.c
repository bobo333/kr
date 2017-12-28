/*
    reverse input one line at a time
*/

#include <stdio.h>

#define MAXLINESIZE 1000

int getlinecustom(char s[]);
void reverseline(char s[], int linesize);

int main() {
    char line[MAXLINESIZE];
    int linesize;

    // get line and length
    // reverse line
    // print reversed line
    while ((linesize = getlinecustom(line)) != 0) {
        reverseline(line, linesize);
        printf("%s\n", line);
    }

    return 0;
}


int getlinecustom(char s[]) {
    int i, c;

    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;

    s[i] = '\0';
    return i;
}


void reverseline(char s[], int linesize) {
    int i;
    char tmp;

    for (i = 0; i < (linesize / 2); ++i) {
        tmp = s[i];

        // extra -1 is to exclude the trailing null terminator
        s[i] = s[linesize - i - 1];
        s[linesize - i - 1] = tmp;
    }
}

