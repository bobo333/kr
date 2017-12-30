/* turn tabs and new lines into \t and \n */
#include <stdio.h>

void escape(char s[], char t[]);

int main() {
    char s[] = "Hello there \tgood sir\nlololol";
    char t[50];
    escape(s, t);
    printf("%s\n", t);

    return 0;
}

void escape(char s[], char t[]) {
    int i, j;
    char c;

    for (i = 0; (c = s[i]) != '\0'; i++) {
        switch (c) {
            case '\t':
                t[j] = '\\';
                j++;
                t[j] = 't';
                j++;
                break;
            case '\n':
                t[j] = '\\';
                j++;
                t[j] = 'n';
                j++;
                break;
            default:
                t[j] = s[i];
                ++j;
                break;
        }
    }

    t[j] = '\0';
}
