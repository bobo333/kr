/* tail n lines of input */
#include <stdio.h>

int strcompare(char *, char*);
int parseposint(char *);
void printlastlines(char *, int);


int main(int argc, char * argv[]) {
    int numlines;
    char c;

    if (argc != 4) {
        printf("Usage: %s -n [lines to tail] [input text]\n", argv[0]);
        return 1;
    }

    if (!strcompare(argv[1], "-n")) {
        printf("Usage: %s -n [lines to tail] [input text]\n", argv[0]);
        return 1;
    }

    numlines = parseposint(argv[2]);
    if (numlines <= 0) {
        printf("2nd argument must be a positive integer, got %s\n", argv[2]);
        return 1;
    }

    printlastlines(argv[3], numlines);

    return 0;
}


int strcompare(char * str1, char * str2) {
    for (; *str1 != '\0' && *str2 != '\0'; str1++, str2++)
        if (*str1 != *str2)
            return 0;
    return 1;
}


int parseposint(char *str) {
    int val = 0;
    char c;

    for (; (c = *str) != '\0'; str++) {
        if (!isdigit(c))
            return -1;

        val = 10 * val + c - '0';
    }

    return val;
}


void printlastlines(char *str, int numlines) {
    int i, newlines;

    // go to end of input string
    for (i = 0; *(str + i) != '\0'; i++)
        ;

    for (newlines = 0; newlines < numlines && i > 0; i--)
        if (*(str + i) == '\n')
            newlines++;

    if (i > 0)
        i += 2; // beginning of string not reached, went past most recent last line
                // so correct here

    printf("%s\n", (str + i));
}
