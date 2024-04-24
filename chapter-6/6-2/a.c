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
void pretty_print(struct tnode *);

static int compare_amount;

int contains(char **lineptr, char *substr, int amount);

int main(int argc, char **argv) {
  char word[MAXWORD];
  int amount;
  if (contains(argv, "-n", argc))
    compare_amount = atoi(argv[2]);

  struct tnode *root;
  root = NULL;

  while (getword(word, MAXWORD) != EOF)
    if (isalpha(word[0]))
      if (isvariable(word) == 0)
        root = addtree(word, root);

  pretty_print(root);
  return 0;
}

struct tnode *addtree(char *word, struct tnode *p) {
  int cond;
  if (p == NULL) {
    p = talloc();
    p->word = strdup(word);
    p->left = p->right = p->group = NULL;
    return p;
  }

  cond = strncmp(word, p->word, compare_amount);

  if (cond < 0)
    p->left = addtree(word, p->left);
  else if (cond > 0)
    p->right = addtree(word, p->right);
  else
    p->group = addtree(word, p->group);

  return p;
}

int contains(char **lineptr, char *substr, int amount) {
  for (int n = 0; n < amount; n++) {
    if (strcmp(*(lineptr + n), substr) == 0)
      return 1;
  }
  return 0;
}

int isvariable(char *word) {
  char **keyword = keywords;
  for (; *keyword != NULL; keyword++)
    if (strcmp(*keyword, word) == 0)
      return 1;
  return 0;
}

struct tnode *talloc(void) {
  return (struct tnode *)malloc(sizeof(struct tnode));
}

void print_group(struct tnode *tree) {
  if (tree != NULL) {
    printf("%s\n", tree->word);
    print_group(tree->group);
  }
}
void pretty_print(struct tnode *tree) {
  if (tree != NULL) {
    pretty_print(tree->left);
    if (tree->group) {
      printf("%s%s:\n", "variables group for ", tree->word);
      print_group(tree->group);
      printf("%s\n", "-----------");
    } else {
      printf("%s\n", tree->word);
    }

    pretty_print(tree->right);
  }
}
