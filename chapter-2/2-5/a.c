#include <stdio.h>

int any(char s1[], char s2[]);

int contains(char s[], char symbol);

int main() {
  int r;
  r = any("12345", "0");
  return printf("%d", r);
}

int any(char s1[], char s2[]) {
  for (int i = 0; s1[i] != '\0'; i++) {
    if (contains(s2, s1[i]))
      return i;
  }
  return -1;
}

int contains(char s[], char symbol) {
  for (int i = 0; s[i] != '\0'; i++) {
    if (s[i] == symbol)
      return 1;
  }
  return 0;
}
