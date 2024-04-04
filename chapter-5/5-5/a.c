#include <stdio.h>

void mystrcpy(char *s, char *t, int n);
void mystrcat(char *s, char *t, int n);
int mystrcmp(char *s, char *t, int n);

int main() {
  int result;
  char str1[16] = "hello world";
  char str2[10];
  mystrcpy(str2, str1, 8);
  printf("%s\n", str2);

  char str3[16] = "hello ";
  char str4[10] = "world!";
  mystrcat(str3, str4, 2);
  printf("%s\n", str3);

  char str5[10] = "qwert";
  char str6[10] = "qwerT";
  int res = mystrcmp(str5, str6, 4);
  printf("%d\n", res);
}
void mystrcpy(char *s, char *t, int n) {
  while (n--)
    *s++ = *t++;
  *s = '\0';
}

void mystrcat(char *s, char *t, int n) {
  while (*s)
    s++;
  while (n--)
    *s++ = *t++;
  *s = '\0';
}

int mystrcmp(char *s, char *t, int n) {
  while (n--)
    if (*s++ != *t++)
      return 1;
  return 0;
}
