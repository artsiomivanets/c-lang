#include <stdio.h>
#define MAXLINE 1000
#define OUTSIDE_COMMENT 2
#define MULTILINE_COMMENT 3
#define SINGLELINE_COMMENT 4
#define INSIDE_STRING 5
#define PRE_COMMENT 6
#define PRE_OUTSIDE_COMMENT 7
#define CLOSED_MULTILINE_COMMENT 8

int get_state(char c, int current_state);

int main() {
  int c, prev, state, comment_type;
  state = OUTSIDE_COMMENT;
  prev = 0;

  while ((c = getchar()) != EOF) {
    state = get_state(c, state);
    if (state == PRE_OUTSIDE_COMMENT || state == SINGLELINE_COMMENT ||
        state == MULTILINE_COMMENT || state == CLOSED_MULTILINE_COMMENT) {
      prev = 0;
    } else if (state == PRE_COMMENT) {
      prev = c;
    } else {
      if (prev)
        putchar(prev);
      prev = 0;
      putchar(c);
    }
  }
  return 0;
}

int get_state(char c, int current_state) {
  switch (current_state) {
  case INSIDE_STRING:
    if (c == '\'' || c == '"')
      return OUTSIDE_COMMENT;
    else
      return INSIDE_STRING;
  case OUTSIDE_COMMENT:
    if (c == '/')
      return PRE_COMMENT;
    else
      return OUTSIDE_COMMENT;
  case SINGLELINE_COMMENT:
    if (c == '\n')
      return OUTSIDE_COMMENT;
    else
      return SINGLELINE_COMMENT;
  case MULTILINE_COMMENT:
    if (c == '*')
      return PRE_OUTSIDE_COMMENT;
  case PRE_OUTSIDE_COMMENT:
    if (c == '/')
      return CLOSED_MULTILINE_COMMENT;
    else
      return MULTILINE_COMMENT;
  case CLOSED_MULTILINE_COMMENT:
    return OUTSIDE_COMMENT;
  case PRE_COMMENT:
    if (c == '/')
      return SINGLELINE_COMMENT;
    else if (c == '*')
      return MULTILINE_COMMENT;
    else
      return OUTSIDE_COMMENT;
  default:
    if (c == '\'' || c == '"')
      return INSIDE_STRING;
    else
      return OUTSIDE_COMMENT;
  }
}
