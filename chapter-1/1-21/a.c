#include <stdio.h>
#define MAXLINE 1000

int mgetline(char line[], int maxline);
void replace_spaces_with_tabs(char line[], int amount);
void copy(char a[], char b[]);

int main() {
  int len;
  char line[MAXLINE];

  while ((len = mgetline(line, MAXLINE)) > 0) {
    replace_spaces_with_tabs(line, 2);
    printf("%s", line);
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

void replace_spaces_with_tabs(char s[], int amount) {
  char result[MAXLINE];
  int i, k, spaces_count;
  i = k = spaces_count = 0;

  while (s[i] != '\0') {
    if (spaces_count == amount) {
      result[k++] = '\t';
      spaces_count = 0;
    }

    if (s[i] == ' ') {
      spaces_count++;
    } else {
      for (int j = 0; j < spaces_count; j++)
        result[k + j] = ' ';
      k = k + spaces_count;
      result[k++] = s[i];
      spaces_count = 0;
    }
    i++;
  }
  result[k] = '\0';

  copy(result, s);
}

void copy(char from[], char to[]) {
  int i = 0;
  while ((to[i] = from[i]) != '\0')
    i++;
}
