/*
Delete all characters in string1 that exist in string2
*/
#include <stdio.h>

void populatestring(char s[]);
void removestringchars(char s1[], char s2[]);

int main() {
    char string1[50];
    char string2[50];

    printf("Input starting string:\n");
    populatestring(string1);
    printf("Input removal string:\n");
    populatestring(string2);

    removestringchars(string1, string2);
    printf("%s\n", string1);

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

void removestringchars(char string1[], char string2[]) {
    int readpos, writepos, testpos, copy;
    char cur, testchar;

    readpos = writepos = testpos = 0;

    for (readpos = 0; (cur = string1[readpos]) != '\0'; ++readpos) {
        testpos = 0;
        copy = 1;
        while ((testchar = string2[testpos++]) != '\0' && copy) {
            if (testchar == cur)
                copy = 0;
        }
        if (copy)
            string1[writepos++] = string1[readpos];
    }

    string1[writepos] = '\0';
}
