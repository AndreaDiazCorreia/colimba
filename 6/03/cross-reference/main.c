#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXWORD 100

/*6.3*/

struct tnode {
    char *word;
    struct tnode *left;
    struct tnode *right;
    int count;
    long *lineNumbers;
};

int noise(char *s);
struct tnode *addtree(struct tnode *, char *, long);
void treeprint(struct tnode *);
int getword(char *, int);

long lineNumber = 1;

int main() {
    struct tnode *root = NULL;
    char word[MAXWORD];

    while (getword(word, MAXWORD) != EOF) {
        if (isalpha(word[0]) && !noise(word)) {
            root = addtree(root, word, lineNumber);
        }
    }

    treeprint(root);
    return 0;
}

int noise(char *s) {
    int found = 0;
    int giveup = 0;

    char *list[] = {
        "a",
        "an",
        "and",
        "be",
        "but",
        "by",
        "he",
        "I",
        "is",
        "it",
        "of",
        "off",
        "on",
        "she",
        "so",
        "the",
        "they",
        "to",
        "you"
    };

    int top = sizeof list / sizeof list[0] - 1;
    int bottom = 0;
    int guess = top / 2;
    int diff = 0;

    if(s != NULL) {
        while(!found && !giveup) {
            diff = strcmp(list[guess], s);
            if(0 == diff) {
                found = 1;
            } else if(0 < diff) {
                top = guess - 1;
            } else {
                bottom = guess + 1;
            }

            if(top < bottom) {
                giveup = 1;
            } else {
                guess = (top + bottom) / 2;
            }
        }
    }

    return found;
}

struct tnode *talloc(void);
char *my_strdup(char *);
int comp(const void *s1, const void *s2);

/* addtree: add a new with w, at or below p */
struct tnode *addtree(struct tnode *p, char *w, long lineNumber) {
    int i;
    if (p == NULL) {
        p = (struct tnode *)malloc(sizeof(struct tnode));
        p->word = my_strdup(w);
        p->count = 1;
        p->lineNumbers = (long *)malloc(sizeof(long));
        p->lineNumbers[0] = lineNumber;
        p->left = p->right = NULL;
    } else {
        int cond = strcmp(w, p->word);
        if (cond == 0) {
            for (i = 0; i < p->count; i++) {
                if (lineNumber == p->lineNumbers[i]) {
                    return p;
                }
            }
            p->count++;
            p->lineNumbers = (long *)realloc(p->lineNumbers, p->count * sizeof(long));
            p->lineNumbers[p->count - 1] = lineNumber;
        } else if (cond < 0) {
            p->left = addtree(p->left, w, lineNumber);
        } else {
            p->right = addtree(p->right, w, lineNumber);
        }
    }
    return p;
}

void treeprint(struct tnode *p) {
    int i;
    if (p != NULL) {
        treeprint(p->left);

        if (p->count > 1 && strlen(p->word) > 1) {
            printf("%12s:\t", p->word);
            for (i = 0; i < p->count; i++) {
                printf("%lu%s", p->lineNumbers[i], (i == p->count - 1) ? "\n" : ", ");
            }
        }

        treeprint(p->right);
    }
}

/* talloc: make a tnode */
struct tnode *talloc(void) {
    return (struct tnode *) malloc(sizeof(struct tnode));
}

char *my_strdup(char *s) {
    char *p = (char *)malloc(strlen(s) + 1);
    if (p != NULL) {
        strcpy(p, s);
    }
    return p;
}

int getch(void);
void ungetch(int);

/* getword: get next word or character from input */
int getword(char *word, int lim) {
    int c;
    char *w = word;

    while (isspace(c = getch()))
        if (c == '\n')
            lineNumber++;

    if (c != EOF)
        *w++ = c;

    if (!isalpha(c)) {
        *w = '\0';
        return c;
    }

    for (;--lim > 0; w++)
        if (!isalpha(*w = getch())) {
            ungetch(*w);
            break;
        }
    *w = '\0';
    return word[0];
}

#define BUFSIZE 100

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0;

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
