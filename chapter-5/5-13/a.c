#include "../alloc/a.c"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_LINES 10
#define MAX_LINES 100
#define MAX_LINE 100

int mgetline(char s[], int lim);
int get_line_from_arg(char **s);

int main(int argc, char **argv) {
  char *lineptr[MAX_LINES];
  char *p;
  char line[MAX_LINE];
  int last_lines;
  int len;
  int nlines = 0;

  while ((len = mgetline(line, MAX_LINE))) {
    if (nlines <= MAX_LINES && (p = alloc(len))) {
      line[len - 1] = '\0';
      strcpy(p, line);
      lineptr[nlines++] = p;
    } else {
      printf("Too many symbols in line");
      return 1;
    }
  }

  last_lines = get_line_from_arg(argv);

  int print_lines = nlines - last_lines;
  for (int n = print_lines < 0 ? 0 : print_lines; n < nlines; n++)
    printf("%s\n", lineptr[n]);

  return 0;
}

int get_line_from_arg(char **s) {
  if (*(s + 1) != NULL)
    return atoi(*(s + 2));
  else
    return DEFAULT_LINES;
}

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
