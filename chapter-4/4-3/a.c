#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define NUMBER '0'
#define MAXNUM 100
#define MAXSTACK 1000

void push(double f);
double pop(void);
int getch(void);
void ungetch(char c);
int getop(char s[]);

int main() {
  char s[MAXNUM];
  int type, op2;

  while ((type = getop(s)) != EOF) {
    switch (type) {
    case NUMBER:
      push(atof(s));
      break;
    case '+':
      push(pop() + pop());
      break;
    case '*':
      push(pop() * pop());
      break;
    case '-':
      op2 = pop();
      push(pop() - op2);
      break;
    case '%':
      op2 = pop();
      push(pop() - op2);
      break;
    case '/':
      op2 = pop();
      if (op2 != 0)
        push(pop() / op2);
      else
        printf("error: zero division");
      break;
    case '\n':
      printf("\t%.8g\n", pop());
      break;
    }
  }

  return 0;
}

int val[MAXSTACK];
int sp = 0;
void push(double f) {
  if (sp < MAXSTACK) {
    val[sp++] = f;
  } else {
    printf("error: stack overflow has been encountered");
  }
}

double pop(void) {
  if (sp > 0) {
    return val[--sp];
  } else {
    printf("error: stack empty");
    return 0.0;
  }
}
int getop(char s[]) {
  int c, i;
  int type;

  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  s[1] = '\0';
  if (!isdigit(c) && c != '.')
    return c;

  i = 0;
  if (isdigit(c))
    while (isdigit(s[++i] = c = getch()))
      ;
  if (c == '.')
    while (isdigit(s[++i] = c = getch()))
      ;
  s[i] = '\0';

  if (c != EOF)
    ungetch(c);

  return NUMBER;
}

char buffer[100];
int bp = 0;

int getch(void) { return bp > 0 ? buffer[--bp] : getchar(); }

void ungetch(char c) { buffer[bp++] = c; }
