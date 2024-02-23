#include <stdio.h>

int main() {
  char c, s[10];
  int i, lim;

  i = 0;
  lim = 5;
  while (1) {
    if (i >= lim - 1)
      break;
    if ((c = getchar()) == '\n')
      break;
    if (c == EOF)
      break;
    s[i] = c;
    i++;
  }
  s[i] = '\0';
  printf("%s", s);
  return 0;
}
