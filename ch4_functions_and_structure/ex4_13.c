/* recursive reverse string */
#include <stdio.h>
#include <string.h> // for strlen

void recreverse(char [], int);


int main() {

    char mystring[] = "hi there";

    recreverse(mystring, strlen(mystring));

    printf("%s\n", mystring);

    return 0;
}

void recreverse(char v[], int l) {
    int i;
    char first;

    first = v[0];

    for (i = 1; i < l; i++) {
        v[i-1] = v[i];
    }
    v[l - 1] = first;

    if (l > 1)
        recreverse(v, l - 1);
}
