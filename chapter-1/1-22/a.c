#include <stdio.h>
#define MAXLINE 1000
#define MAXCOL 10

int mgetline(char line[], int maxline);
void copy(char a[], char b[]);
void fold_by_column(char line[], int col);
int take_word(char from[], char to[]);

int main() {
  int len;
  char line[MAXLINE];

  while ((len = mgetline(line, MAXLINE)) > 0) {
    fold_by_column(line, MAXCOL);
  }
  return 0;
}

void fold_by_column(char line[], int col_limit) {
  char restricted_line[col_limit];
  int c, i, current_col, last_blank, last_blank_restricted, too_long_word,
      enough_space;
  c = i = current_col = last_blank = last_blank_restricted = 0;

  while ((c = line[i]) != '\0') {
    enough_space = current_col < col_limit;

    if (c == ' ') {
      last_blank = i;
      last_blank_restricted = current_col;
    }

    if (c == '\n') {
      restricted_line[current_col] = '\0';
      printf("%s\n", restricted_line);
      i++;
      continue;
    }

    if (enough_space) {
      restricted_line[current_col] = c;
      i++;
      current_col++;
      continue;
    }

    if (c == ' ') {
      restricted_line[current_col] = '\0';
      i++;
    } else if (line[i - 1] == ' ') {
      restricted_line[current_col - 1] = '\0';
    } else {
      restricted_line[last_blank_restricted] = '\0';
      i = last_blank + 1;
    }

    printf("%s", restricted_line);
    printf("\n");
    current_col = 0;
  }
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
  return i;
}

void copy(char from[], char to[]) {
  int i = 0;
  while ((to[i] = from[i]) != '\0')
    i++;
}
