#include <stdio.h>
#include <string.h>

void itoa(signed char n, char s[]);
void reverse(char s[]);

int main() {
  char t[100];
  itoa((char)-128, t);
  printf("%s", t);
  return 0;
}
void reverse(char s[]) {
  int c, i, j;
  for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}

void itoa(signed char c, char s[]) {
  int i, sign;
  unsigned char n;
  n = c;
  if ((sign = c) < 0) /* record sign */
    n = -c;           /* make n positive */
  i = 0;
  do {                     /* generate digits in reverse order */
    s[i++] = n % 10 + '0'; /* get next digit */
  } while ((n /= 10) > 0); /* delete it */
  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';
  reverse(s);
}
