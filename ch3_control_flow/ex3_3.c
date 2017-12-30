/* expand ranges of letters to the full letter set */
#include <stdio.h>

#define DASH '-'

void expand(char s[], char t[]);

int main() {

    char input[] = "a-f -g-f-z hahaha 0-3-5";
    char output[500];

    expand(input, output);

    printf("%s\nbecame\n%s\n", input, output);

    return 0;
}


void expand(char in[], char out[]) {

    char low, high;
    int i, j;

    for (i = 0, j = 0; in[i] != '\0'; i++) {
        if (in[i+1] != DASH)
            out[j++] = in[i];
        else {
            low = in[i];
            high = in[i+2];

            if (high < low) {
                out[j++] = in[i];
            } else if ( (low >= 'a' && high <= 'z') ||
                        (low >= 'A' && high <= 'Z') ||
                        (low >= '0' && high <= '9') ) {
                for (; low <= high; low++, j++) {
                    out[j] = low;
                }

                i += 2;
            } else {
                out[j++] = in[i];
            }
        }
    }
    out[j] = '\0';
}
