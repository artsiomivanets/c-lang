#include <stdio.h>

void expand(char s[], char t[]);

int main() {
  char t[100];
  expand("a-b-z0-2-5A-C", t);
  printf("%s", t);
  return 0;
}

void expand(char s[], char t[]) {
  int i, j, start, end;
  i = j = start = end = 0;

  while (s[i] != '\0') {
    if (!start) {
      start = s[i];
      i++;
    } else if (start && end && s[i + 1] != '-') {
      while (start <= end) {
        t[j++] = start;
        start++;
      }
      start = end = 0;
      i++;
    } else if (start && !end && s[i] != '-') {
      end = s[i];
    } else {
      end = 0;
      i++;
    }
  }
  t[j] = '\0';
}
