#include <stdio.h>

#define BLANK ' '
#define TRUE 1
#define FALSE 0

int main() {
    
    int c, print_blank;

    print_blank = TRUE;
    while ((c = getchar()) != EOF) {
        if (c == BLANK) {
            if (print_blank) {
                putchar(BLANK);
                print_blank = FALSE;
            }
        } else {
            putchar(c);
            print_blank = TRUE;
        }
    }

    return 0;
}
