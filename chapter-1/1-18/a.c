/*
 * I'm going to change 80 characters to 10 characters
 * to make it easier to test
 *
 */

#include <stdio.h>
#define MAXLINE 1000

int mgetline(char line[], int maxline);
int remove_blanks(char line[]);

int main() {
  int len, len_without_blanks;
  char line[MAXLINE];

  while ((len = mgetline(line, MAXLINE)) > 0) {
    len_without_blanks = remove_blanks(line);
    if (len_without_blanks > 0) {
      printf("%s\n", line);
    }
  }
  return 0;
}

int remove_blanks(char s[]) {
  int i, pos;
  i = pos = 0;

  while (s[i] != '\0') {
    if (s[i] != '\t' && s[i] != ' ' && s[i] != '\n') {
      s[pos] = s[i];
      pos++;
    }
    i++;
  }
  s[pos] = '\0';
  return pos;
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
