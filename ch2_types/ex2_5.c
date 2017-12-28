/*
Find first occurrence in string1 of any char in string2
*/
#include <stdio.h>

void populatestring(char s[]);
int findfirstoccurrence(char s1[], char s2[]);

int main() {
    char string1[50];
    char string2[50];
    int firstoccurrence;

    printf("Input starting string:\n");
    populatestring(string1);
    printf("Input search string:\n");
    populatestring(string2);

    firstoccurrence = findfirstoccurrence(string1, string2);
    printf("%d\n", firstoccurrence);

    return 0;
}

void populatestring(char s[]) {
    char c;
    int i;

    for (i = 0; (c = getchar()) != '\n'; i++) {
        s[i] = c;
    }
    s[i] = '\0';
}

int findfirstoccurrence(char string1[], char string2[]) {
    int readpos, testpos;
    char cur, testchar;

    readpos = 0;

    while ((cur = string1[readpos++]) != '\0') {
        testpos = 0;
        while ((testchar = string2[testpos++]) != '\0') {
            if (testchar == cur)
                return --readpos;
        }
    }
    return -1;
}
