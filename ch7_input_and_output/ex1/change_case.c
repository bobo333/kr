#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <libgen.h>


int main(int argc, char *argv[]) {
    char command;

    if (strcmp(basename(argv[0]), "upper") == 0) {
        command = 'u';
    } else if (strcmp(basename(argv[0]), "lower") == 0) {
        command = 'l';
    } else {
        return 1;
    }


    char c;

    while ((c = getchar()) != EOF) {
        switch (command) {
            case 'l':
                putchar(tolower(c));
                break;
            case 'u':
                putchar(toupper(c));
                break;
        }
    }

    return 0;
}

