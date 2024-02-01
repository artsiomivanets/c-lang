#include <stdio.h>

#define BLANK ' '
#define TAB '\t'
#define NL '\n'

int main() {
  int blanks, tabs, newlines;
  int c;

  blanks = tabs = newlines = 0;

  while ((c = getchar()) != EOF) {
    if (c == BLANK) {
      blanks++;
    } else if (c == TAB) {
      tabs++;
    } else if (c == NL) {
      newlines++;
    }
  }

  printf("Blanks: %d\n", blanks);
  printf("Tabs: %d\n", tabs);
  printf("New lines: %d\n", newlines);
}

/*
  In my current system EOF is -1

  gcc a.c && ./a.out
  -1

 */
