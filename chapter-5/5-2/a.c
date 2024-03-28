#include <ctype.h>
#include <stdio.h>

#define NUMBER '0'
#define SIZE 100

int getch(void);
void ungetch(char c);
int getfloat(float *pn);

int main() {
  int n;
  float numbers[SIZE];

  for (n = 0; n < SIZE && getfloat(&numbers[n]) != EOF; n++)
    ;

  for (n = 0; n < 2; n++)
    printf("%f\n", numbers[n]);
  return 0;
}

char buffer[100];
int bp = 0;

int getfloat(float *pn) {
  int c, i, sign = 1;

  while (isspace(c = getch()))
    ;
  if (c == EOF)
    return EOF;

  if (c == '-') {
    sign = -1;
    c = getch();
  }

  for (*pn = 0; c != '.'; c = getch())
    *pn = 10 * *pn + (c - '0');

  c = getch();
  for (i = 0; isdigit(c) && ++i; c = getch())
    *pn = 10 * *pn + (c - '0');

  for (; i > 0; i--)
    *pn = *pn / 10.0;
  *pn = *pn * sign;

  if (c != EOF)
    ungetch(c);

  return c;
}

int getch(void) { return bp > 0 ? buffer[--bp] : getchar(); }

void ungetch(char c) { buffer[bp++] = c; }
