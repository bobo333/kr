#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// #define HASHSIZE 101

// use 1 to make sure the linked list updates are working
#define HASHSIZE 1

struct nlist {
    struct nlist *next;
    char *name;
    char *defn;
};

unsigned hash(char *);
struct nlist *lookup(char *);
struct nlist *install(char *, char *);
void undef(char *);
void is_present(char *);


// pointer to table of pointers to nlist
static struct nlist *hashtab[HASHSIZE]; // pointer table


int main() {
    install("bob", "uncle");
    undef("bob");

    is_present("bob");

    install("bob", "better uncle");

    is_present("hi");

    install("hi", "there");
    install("lol", "lol");

    is_present("hi");

    undef("hi");

    is_present("hi");
    is_present("bob");
    is_present("lol");

    return 0;
}


/* hash: form hash value for strings */
unsigned hash(char *s) {
    unsigned hashval;

    for (hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}


/* lookup: look for s in hashtab */
struct nlist *lookup(char *s) {
    struct nlist *np;

    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->name) == 0)
            return np;
    return NULL;
}


/* install: put (name, defn) in hashtab */
struct nlist *install(char *name, char *defn) {
    struct nlist *np;
    unsigned hashval;

    if ((np = lookup(name)) == NULL) {  // not found
        np = (struct nlist *) malloc(sizeof(*np));
        if (np == NULL || (np->name = strdup(name)) == NULL)
            return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval];    // attach cur nlist at hash location to new
                                        // nlist about to be inserted
        hashtab[hashval] = np;          // insert new nlist where previous nlist was
    } else  // already there
        free((void *) np->defn);    // free previous defn

    if ((np->defn = strdup(defn)) == NULL)
        return NULL;
    return np;
}


void undef(char *s) {
    struct nlist *parent_np;
    struct nlist *np;
    unsigned hashval;

    if ((np = lookup(s)) == NULL)   // doesn't exists
        return;

    hashval = hash(s);
    if (hashtab[hashval] == np) {   // it's the first value
        if (np->next != NULL)
            hashtab[hashval] = np->next;
        else
            hashtab[hashval] = NULL;

        free((void *) np);
    } else {    // must find it in the list and track parent
        for (parent_np = hashtab[hashval]; parent_np->next != np; parent_np = parent_np->next)
            ;
        parent_np->next = np->next; // cut it from the list, shoul be OK even if np->next is NULL

        free((void *) np);
    }
}


void is_present(char *s) {
    printf("%s ", s);
    if (lookup(s) == NULL)
        printf("not there\n");
    else
        printf("found\n");
}
