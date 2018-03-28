#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100
#define NKEYS (sizeof keytab / sizeof keytab[0])
#define BUFSIZE 100

struct key {
    char *word;
    int count;
} keytab[] = {
    "auto", 0,
    "break", 0,
    "case", 0,
    "char", 0,
    "const", 0,
    "continue", 0,
    "default", 0,
    "unsigned", 0,
    "void", 0,
    "volatile", 0,
    "while", 0
};

char letter_buffer[BUFSIZE];
int lc = 0;

int getword(char *, int);
int binsearch(char *, struct key *, int);
int getch(void);
void ungetch(int);


/* count C keywords */
int main() {
    int n;
    char word[MAXWORD];

    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            if ((n = binsearch(word, keytab, NKEYS)) >= 0)
                keytab[n].count++;
    
    for (n = 0; n < NKEYS; n++)
        if (keytab[n].count > 0)
            printf("%s: %4d\n", keytab[n].word, keytab[n].count);

    return 0;
}


/* binsearch: find word in tab[0]...tab[n-1] */
int binsearch(char *word, struct key tab[], int n) {
    int cond;
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low+high) / 2;
        if ((cond = strcmp(word, tab[mid].word)) < 0)
            high = mid - 1;
        else if (cond > 0)
            low = mid + 1;
        else
            return mid;
    }

    return -1; // not found
}


/* getword: get next word or character from input */
int getword(char *word, int lim) {
    int c, next;
    char *w = word;

    while (isspace(c = getch()))
        ;

    // handle string constants
    if (c == '"')
        while ((c = getch()) != '"')
            ;

    // handle single-line comments
    if (c == '/')
        if ((next = getch()) == '/')
            while ((c = getch()) != '\n')
                ;
        else {
            ungetch(next);
            c = '/';
        }

    // handle end of input
    if (c != EOF)
        *w++ = c;

    // can't start with a number
    if (!isalpha(c)) {
        *w = '\0';
        return c;
    }

    // keep grabbing until not letter or number
    for ( ; --lim > 0; w++)
        if (!isalnum(*w = getch())) {
            ungetch(*w);
            break;
        }

    *w = '\0';
    return word[0];
}


int getch(void) {
    if (lc > 0) 
        return letter_buffer[--lc];
    else
        return getchar();
}

void ungetch(int c) {
    if (lc > BUFSIZE)
        printf("ungetch: too many chars in buffer\n");
    else
        letter_buffer[lc++] = c;
}
