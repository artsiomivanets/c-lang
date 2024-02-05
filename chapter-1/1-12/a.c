#include <stdio.h>

#define IN 1
#define OUT 2

int main() {
  int state, c;
  state = OUT;

  while ((c = getchar()) != EOF) {
    switch (state) {
    case IN:
      if (c == ' ' || c == '\n' || c == '\t') {
        state = OUT;
      } else {
        putchar(c);
      }
      break;
    case OUT:
      if (c == ' ' || c == '\n' || c == '\t') {
        continue;
      } else {
        putchar('\n');
        putchar(c);
        state = IN;
      }
      break;
    default:;
    }
  }
}
