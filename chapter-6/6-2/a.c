#include "../../utils.c"
#include <stdlib.h>
#include <string.h>
#define MAXWORD 100

char *keywords[] = {
    "auto",     "break",  "case",    "char",   "const",    "continue",
    "default",  "do",     "double",  "else",   "enum",     "extern",
    "float",    "for",    "goto",    "if",     "int",      "long",
    "register", "return", "short",   "signed", "sizeof",   "static",
    "struct",   "switch", "typedef", "union",  "unsigned", "void",
    "volatile", "while",
};

struct tnode {
  char *word;
  struct tnode *group;
  struct tnode *left;
  struct tnode *right;
};

struct tnode *addtree(char *word, struct tnode *);
struct tnode *talloc(void);

int getword(char *word, int lim);
int isvariable(char *word);

int main(int argc, char *argv[]) {
  char word[MAXWORD];
  struct tnode *root;
  root = NULL;

  while (getword(word, MAXWORD) != EOF)
    if (isalpha(word[0]))
      if (isvariable(word))
        root = addtree(word, root);

  return 0;
}

struct tnode *addtree(char *word, struct tnode *p) {
  if (p == NULL) {
    p = talloc();
    p->word = strdup(word);
    p->left = p->right = p->group = NULL;
  }

  return p;
}

int isvariable(char *word) {}

struct tnode *talloc(void) {
  return (struct tnode *)malloc(sizeof(struct tnode));
}
