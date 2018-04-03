#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXWORD 100

char buff[1];
int bc = 0;

char getword(char *);
char getch();
void ungetch(char);
struct tnode *addtotree(struct tnode *, char *, int);
void printtree(struct tnode *);
struct tnode *talloc();
struct line *lalloc();

struct line {
    int number;
    struct line *next;
};

struct tnode {
    char *word;
    struct tnode *left;
    struct tnode *right;
    struct line *lines;
};


int main() {
    int line_num;
    struct tnode *root;
    char word[MAXWORD];
    char cur;

    line_num = 1;
    root = NULL;

    while ((cur = getword(word)) != EOF)
        if (cur == '\n')
            line_num++;
        else
            root = addtotree(root, word, line_num);

    printf("\n");
    printtree(root);
    return 0;
}


/* add a new word to the tree, or find existing word and add line number */
struct tnode *addtotree(struct tnode *root, char *word, int line_num) {
    struct line *tmp;
    int cond;

    if (root == NULL) {     // create new node
        root = talloc();
        root->word = strdup(word);
        root->lines = lalloc();
        root->lines->number = line_num;
        root->left = NULL;
        root->right = NULL;
    } else if ((cond = strcmp(word, root->word)) == 0) {    // add to line list
        tmp = root->lines;
        while (tmp->next != NULL && tmp->number != line_num)
            tmp = tmp->next;
        if (tmp->number != line_num) {
            tmp->next = lalloc();
            tmp->next->number = line_num;
            tmp->next->next = NULL;
        }
    } else if (cond < 0) {  // add to left
        root->left = addtotree(root->left, word, line_num);
    } else {    // add to right
        root->right = addtotree(root->right, word, line_num);
    }

    return root;
}


/* print tree, print left of root, then root, then right of root */
void printtree(struct tnode *root) {
    struct line *tmp;

    if (root->left != NULL)
        printtree(root->left);
    
    printf("%s appears on: ", root->word);
    tmp = root->lines;
    for (tmp = root->lines; tmp != NULL; tmp = tmp->next)
        printf("%d ", tmp->number);
    printf("\n");

    if (root->right != NULL)
        printtree(root->right);
}


/* put word or new line in *target*, return first character in target */
char getword(char *target) {
    char cur;

    while (!isalpha(cur = getch()) && cur != EOF && cur != '\n')
        ;

    if (cur == EOF || cur == '\n')
        return cur;

    *target++ = cur;

    while (isalpha(cur = getch()) && cur != EOF && cur != '\n')
        *target++ = cur;

    if (cur == EOF || cur == '\n')
        ungetch(cur);

    *target++ = '\0';
    return target[0];
}


/* return pointer to tnode */
struct tnode *talloc() {
    return (struct tnode *) malloc(sizeof(struct tnode));
}


/* return pointer to line */
struct line *lalloc() {
    return (struct line *) malloc(sizeof(struct line));
}


/* get character from buffer, if buffer empty grab and return new character */
char getch() {
    if (bc > 0)
        return buff[--bc];
    else
        return getchar();
}


/* put a character into the buffer */
void ungetch(char c) {
    buff[bc++] = c;
}
