#include <stdio.h>

void squeeze(char s1[], char s2[]);

int contains(char s[], char symbol);

int main() {
  char s1[4] = "1234";
  squeeze(s1, "321");
  return printf("%s", s1);
}

void squeeze(char s1[], char s2[]) {
  int i, j;
  i = j = 0;
  while (s1[i] != '\0') {
    if (!contains(s2, s1[i])) {
      s1[j++] = s1[i++];
    } else {
      i++;
    }
  }
  s1[j] = '\0';
}

int contains(char s[], char symbol) {
  for (int i = 0; s[i] != '\0'; i++) {
    if (s[i] == symbol)
      return 1;
  }
  return 0;
}
