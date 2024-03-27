#include <math.h>
#include <stdio.h>
#include <string.h>

void reverse(char s[]);
static void reverser(int len, int i, char l[]);

int main() {
  char s1[] = "hello";
  char s3[] = "";
  char s2[] = "ab";

  reverse(s1);
  printf("%s\n", s1);

  reverse(s2);
  printf("%s\n", s2);

  reverse(s3);
  printf("%s\n", s3);

  return 0;
}

void reverse(char s[]) {
  int len = strlen(s);
  reverser(len - 1, 0, s);
}

void reverser(int len, int i, char l[]) {
  if (len <= i)
    return;
  char tmp;
  tmp = l[len];
  l[len] = l[i];
  l[i] = tmp;
  reverser(len - 1, i + 1, l);
}
