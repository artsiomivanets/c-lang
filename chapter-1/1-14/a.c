#include <stdio.h>

#define IN 1
#define OUT 2

#define LENGTH 1000

int main() {
  int c, char_amount[LENGTH];

  for (int i = 0; i < LENGTH; i++)
    char_amount[i] = 0;

  while ((c = getchar()) != EOF)
    char_amount[c]++;

  for (int i = 0; i < LENGTH; i++) {
    char amount = char_amount[i];
    if (!amount)
      continue;
    if (i == ' ') {
      printf("SPACES: ");
    } else if (i == '\t') {
      printf("TABS: ");
    } else if (i == '\n') {
      printf("NL: ");
    } else {
      printf("%c: ", i);
    }
    for (int k = 0; k < amount; k++)
      printf("|");
    printf("\n");
  }
}
