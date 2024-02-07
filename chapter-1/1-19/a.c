#include <stdio.h>
#define MAXLINE 1000

int mgetline(char line[], int maxline);
void reverse(char line[], int length);

int main() {
  int len;
  char line[MAXLINE];

  while ((len = mgetline(line, MAXLINE)) > 0) {
    reverse(line, len);
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

void reverse(char s[], int length) {
  char temp;
  if (s[length - 1] == '\n') {
    s[length - 1] = '\0';
    --length;
  }
  for (int i = 0; i < length; i++) {
    --length;
    temp = s[i];
    s[i] = s[length];
    s[length] = temp;
  }
}
