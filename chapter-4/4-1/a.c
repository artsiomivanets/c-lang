#include <stdio.h>

int strindex(char s[], char t[]);

int main() {
  printf("%d\n", strindex("hello world", "o"));
  printf("%d\n", strindex("I'm here to print something interesting", "ing"));
  printf("%d\n", strindex("nothing has been found", "z"));
  return 0;
}

int strindex(char s[], char t[]) {
  int last, index;
  int i, j;
  last = index = -1;

  for (i = 0; s[i] != '\0'; i++) {
    for (j = 0; t[j] == s[i]; j++) {
      index = index == -1 ? i : index;
      i++;
    }
    if (t[j] == '\0') {
      j = 0;
      last = index;
    }
    index = -1;
  }

  return last;
}
