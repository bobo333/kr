#include <stdio.h>

int main() {
    
    int c, num_spaces, num_tabs, num_nl;
    c = num_spaces = num_tabs = num_nl = 0;

    while((c = getchar()) != EOF) {
        if (c == ' ')
            num_spaces++;
        if (c == '\t')
            num_tabs++;
        if (c == '\n')
            num_nl++;
    }

    printf("spaces:\t\t%d\n", num_spaces);
    printf("tabs:\t\t%d\n", num_tabs);
    printf("new lines:\t%d\n", num_nl);

    return 0;
}
