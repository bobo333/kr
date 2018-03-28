/* read and sort lines with pointers */
#include <stdio.h>
// #include <stdlib.h> /* for malloc */
#include <string.h>

#define MAXLINES 5000   /* max # lines to be sorted */


char *lineptr[MAXLINES];    /* pointers to text lines */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort_custom(char *lineptr[], int left, int right);

/* sort input lines */
int main() {

    int nlines; /* number of input lines read */

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        qsort_custom(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
}


#define MAXLEN 1000 /* max length of any input line */
int getline_custom(char *, int);
char *alloc(int);

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines) {
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = getline_custom(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p = alloc(len + 1)) == NULL) // needs to be len + 1 to account for '\0' at end
            return -1;
        else {
            // line[len-1] = '\0'; /* delete newline */ //turns out this isn't needed
            strcpy(p, line);
            lineptr[nlines++] = p;
        }

    return nlines;
}


/* writelines: write outout lines */
void writelines(char *lineptr[], int nlines) {

    while (nlines-- > 0)
        printf("%s\n", *lineptr++);
}


/* qsort_custom: sort v[left]...v[right] into increasing order */
void qsort_custom(char *v[], int left, int right) {
    int i, last;
    void swap(char *v[], int i, int j);

    if (left >= right) /* do nothing if array contains fewer than 2 elements */
        return;

    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort_custom(v, left, last-1);
    qsort_custom(v, last + 1, right);
}


/* swap: interchange v[i] and v[j] */
void swap(char *v[], int i, int j) {
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}


/* getline_custom: get input line */
int getline_custom(char *v, int max) {
    char c;
    int i;

    for (i = 0; (c = getchar()) != EOF && c != '\n' && i < max - 1; i++)
        *(v + i) = c;
    *(v + i) = '\0';

    return i;
}


/* alloc */
static int memcounter = 0;
#define MAXMEMSIZE  (MAXLINES * MAXLEN)
char membuffer[MAXMEMSIZE];

char * alloc(int size) {
    char *p;

    if (memcounter + size > MAXMEMSIZE)
        return NULL;
    else {
        p = (membuffer + memcounter);
        memcounter += size;
        return p;
    }
}
