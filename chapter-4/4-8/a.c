#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define NUMBER '0'
#define LETTER '1'
#define MAXNUM 100
#define MAXSTACK 1000
#define MAXVARIABLES 1000

void push(double f);
double pop(void);
int getch(void);
void ungetch(char c);
void ungets(char s[]);
int getop(char s[]);
void show_last_two_op(void);
void swap_last_two_op(void);
void duplicate_last_two_op(void);

int variables[MAXVARIABLES];

int main() {
  char s[MAXNUM];
  int type, op2;
  for (int i = 0; i < MAXVARIABLES; i++)
    variables[i] = 0;

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
    case '!':
      show_last_two_op();
      break;
    case '@':
      duplicate_last_two_op();
      break;
    case '#':
      swap_last_two_op();
      break;
    case '~':
      push(sin(pop()));
      break;
    case '`':
      push(cos(pop()));
      break;
    case LETTER:
      if (variables[s[0]])
        push(variables[s[0]]);
      else
        variables[s[0]] = pop();
      break;
    }
  }

  return 0;
}

double val[MAXSTACK];
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
    printf("Top of the stack: %f, %f", val[sp - 1], val[sp - 2]);
  else if (sp == 1)
    printf("Top of the stack: %f", val[sp - 1]);
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
  if (isalpha(c))
    return LETTER;
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

char temp_buf = '\0';

int getch(void) {
  char result;
  if (temp_buf) {
    result = temp_buf;
    temp_buf = '\0';
  } else {
    result = getchar();
  }
  return result;
}

void ungets(char s[]) {
  int i = 0;
  while (s[i] != '\0')
    ungetch(s[i++]);
}

void ungetch(char c) { temp_buf = c; }
