/* recursive itoa int to character array */
#include <stdio.h>

void atoirec(int, char []);
void putcharcust(char, char[]);

int main() {

    int input;
    char output[50];
    output[0] = '\0';

    input = -56789;

    atoirec(input, output);

    printf("%d became %s\n", input, output);

    return 0;
}


void atoirec(int input, char output[]) {

    if (input < 0) {
        putcharcust('-', output);
        input = -1 * input;
    }

    if (input >= 10)
        atoirec(input / 10, output);

    putcharcust(input % 10 + '0', output);
}


void putcharcust(char c, char v[]) {
    int i;

    for (i = 0; v[i] != '\0'; i++)
        ;

    v[i] = c;
    v[i+1] = '\0';
}
