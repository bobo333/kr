/* manipulate string via pointer */
#include <stdio.h>

int main() {
    char s[] = "hello";
    char *p;
    p = s;
    *(p + 3) = 'g';

    printf("%s\n", s);
    printf("%s\n", p);

    return 0;
}
