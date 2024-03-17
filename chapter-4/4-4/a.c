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
void show_last_two_op(void);
void swap_last_two_op(void);
void duplicate_last_two_op(void);

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
    case '/':
      op2 = pop();
      if (op2 != 0)
        push(pop() / op2);
      else
        printf("error: zero division");
      break;
    case 'P':
      show_last_two_op();
      break;
    case 'D':
      duplicate_last_two_op();
      break;
    case 'S':
      swap_last_two_op();
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

void show_last_two_op(void) {
  if (sp > 1)
    printf("Top of the stack: %d, %d", val[sp - 1], val[sp - 2]);
  else if (sp == 1)
    printf("Top of the stack: %d", val[sp - 1]);
  else
    printf("Error: too few elements in stack");
}

void duplicate_last_two_op(void) {
  int op1, op2;
  if (sp > 1) {
    op1 = val[sp - 2];
    op2 = val[sp - 1];
    push(op1);
    push(op2);
    show_last_two_op();
  } else {
    printf("Error: not enough elements to duplicate");
  }
}

void swap_last_two_op(void) {
  int op1, op2;
  if (sp > 1) {
    op2 = pop();
    op1 = pop();
    push(op2);
    push(op1);
    show_last_two_op();
  } else {
    printf("Error: not enough elements to duplicate");
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
