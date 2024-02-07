#include <stdio.h>
#define MAXLINE 1000

int mgetline(char line[], int maxline);
void replace_tabs_with_spaces(char line[], int amount);

int main() {
  int len;
  char line[MAXLINE];

  while ((len = mgetline(line, MAXLINE)) > 0) {
    replace_tabs_with_spaces(line, 2);
    printf("%s\n", line);
  }
  return 0;
}

int mgetline(char s[], int lim) {
  int c, i;
  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

void replace_tabs_with_spaces(char s[], int amount) {
  char result[MAXLINE];
  int i, k, j;
  i = k = 0;

  while (s[i] != '\0') {
    if (s[i] == '\t') {
      for (j = 0; j < amount; j++)
        result[k + j] = ' ';
      k = k + j;
    } else {
      result[k] = s[i];
      k++;
    }
    i++;
  }
  result[++k] = '\0';

  i = 0;
  while ((s[i] = result[i]) != '\0')
    i++;
}
