#include <stdio.h>

#define IN 1
#define OUT 2

int main() {
  int c, words_length[10], state, nc;
  state = OUT;

  for (int i = 0; i < 10; i++)
    words_length[i] = 0;

  while ((c = getchar()) != EOF) {
    if (IN) {
      if (c == ' ' || c == '\t' || c == '\n') {
        state = OUT;
        words_length[nc]++;
        nc = 0;
      } else {
        ++nc;
      }
    } else if (OUT) {
      if (c == ' ' || c == '\t' || c == '\n') {
        continue;
      } else {
        state = IN;
        ++nc;
      }
    }
  }

  for (int i = 0; i < 10; i++) {
    printf("%d: ", i);
    for (int k = 0; k < words_length[i]; k++)
      printf("|");
    printf("\n");
  }
}
