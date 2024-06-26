#include "../alloc/a.c"
#include <stdio.h>
#include <string.h>
#define MAXLINES 5000
#define MAXLEN 1000
char *lineptr[MAXLINES];

int mgetline(char s[], int lim);
int readlines(char *lineptr[], int nlines);

int mgetline(char s[], int lim) {
  int c, i;
  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';

  return i == 1 ? 0 : i;
}
int readlines(char *lineptr[], int maxlines) {
  int len, nlines;
  char *p, line[MAXLEN];
  nlines = 0;
  while ((len = mgetline(line, MAXLEN)) > 0)
    if (nlines >= maxlines || (p = alloc(len)) == NULL)
      return -1;
    else {
      line[len - 1] = '\0';
      strcpy(p, line);
      lineptr[nlines++] = p;
    }
  return nlines;
}
void writelines(char *lineptr[], int nlines) {
  int i;
  for (i = 0; i < nlines; i++)
    printf("%s\n", lineptr[i]);
}
