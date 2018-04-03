#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100

struct tnode {
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);
struct tnode *talloc(void);
char *strdup_custom(char *);

/* word frequency count */
int main() {
    struct tnode *root;
    char word[MAXWORD];

    root = NULL;
    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            root = addtree(root, word);
    treeprint(root);
    return 0;
}

/* addtree: add a node with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w) {
    int cond;

    if (p == NULL) {    // a new word has arrived
        p = talloc();   // make a new node
        p->word = strdup_custom(w);
        p->count = 1;
        p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0)
        p->count++;     // repeated word
    else if (cond < 0)
        p->left = addtree(p->left, w);
    else
        p->right = addtree(p->right, w);
    return p;
}

/* treeprint: in-order print of tree p*/
void treeprint(struct tnode *p) {
    if (p != NULL) {
        treeprint(p->left);
        printf("%4d %s\n", p->count, p->word);
        treeprint(p->right);
    }
}

/* talloc: make a tnode */
struct tnode *talloc(void) {
    return (struct tnode *) malloc(sizeof(struct tnode));
}

char *strdup_custom(char *s) {     // make a duplicate of s
    char *p;

    p = (char *) malloc(strlen(s) + 1);     // +1 for '\0'
    if (p != NULL)
        strcpy(p, s);
    return p;
}

int getword(char *target, int max_len) {
    char cur;
    char *t = target;

    while (!isalpha(cur = getchar()) && cur != EOF) // skip spaces
        ;

    if (cur == EOF)   // end of input
        return cur;
    else
        *t++ = cur;

    while (--max_len > 0 && isalpha(cur = getchar()))
        *t++ = cur;

    *t = '\0';
    return target[0];
}
