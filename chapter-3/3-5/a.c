#include <stdio.h>
#include <string.h>

void itob(int n, char s[], int b);
void reverse(char s[]);

int main() {
  char t[100];
  itob(-16, t, 16);
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

void itob(int n, char s[], int b) {
  int i, reminder, result, sign;
  if ((sign = n) < 0)
    n = -n;
  reminder = 1;
  i = 0;
  do {
    switch (b) {
    case 2:
      if (sign > 0) {
        result = n % b + '0';
      } else {
        reminder += !(n % b);
        result = !(reminder -= reminder >= 0 ? 1 : 0) + '0';
      }
      break;
    case 10:
      result = n % b + '0';
      break;
    case 16:
      if (sign > 0) {
        reminder = n % b;
        result = reminder + '0';
        if (reminder > 9)
          result += 7;
      } else {
        reminder = b - (n % b);
        result = reminder + '0';
        if (reminder > 9)
          result += 7;
      }
      break;
    }
    s[i++] = result;
  } while ((n /= b) > 0);
  if (b == 10 && sign < 0) {
    s[i++] = '-';
  }
  s[i] = '\0';
  reverse(s);
}
