#include <ctype.h>
#include <stdio.h>

char *mystrcat(char *s, char *t);

int main() {
  int n;
  char str1[] = "hello ";
  char str2[] = "world!";
  mystrcat(str1, str2);
  printf("%s", str1);
  return 0;
}

char *mystrcat(char *s, char *t) {
  while (*s)
    s++;
  while ((*s++ = *t++))
    ;
  return s;
}
