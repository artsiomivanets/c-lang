#include <stdio.h>

void escape(char s[], char t[]);
void unescape(char s[], char t[]);

int main() {
  char t[100];
  unescape("asdf\\tasdf\\nasdf", t);
  printf("%s", t);
  return 0;
}

void escape(char s[], char t[]) {
  int i, j;
  char c;
  j = i = 0;
  while (s[i] != '\0') {
    c = s[i];
    switch (c) {
    case '\n':
      t[j++] = '\\';
      t[j++] = 'n';
      i++;
      break;
    case '\t':
      t[j++] = '\\';
      t[j++] = 't';
      i++;
      break;
    default:
      t[j++] = c;
      i++;
      break;
    }
  }
  t[j] = '\0';
}

void unescape(char s[], char t[]) {
  int i, j;
  char c;
  j = i = 0;
  while (s[i] != '\0') {
    c = s[i];
    switch (c) {
    case '\\':
      c = s[++i]; // moving forward to get escape char
    case 'n':
    case 't':
      t[j++] = c == 'n' ? '\n' : '\t';
      i++;
      break;
    default:
      t[j++] = c;
      i++;
      break;
    }
  }
  t[j] = '\0';
}
