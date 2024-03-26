#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define NUMBER '0'
#define LETTER '1'
#define END '\0'
#define MAXNUM 100
#define MAXSTACK 1000
#define MAXVARIABLES 1000

void push(double f);
double pop(void);
int getop(char s[], char input[], size_t len);
void show_last_two_op(void);
void swap_last_two_op(void);
void duplicate_last_two_op(void);

int variables[MAXVARIABLES];
int line_counter = 0;

int main() {
  char s[MAXNUM];
  int type, op2;
  for (int i = 0; i < MAXVARIABLES; i++)
    variables[i] = 0;

  char *line = NULL;
  size_t len = 0;
  int line_size = 0;
  line_size = getline(&line, &len, stdin);

  while ((type = getop(s, line, len)) != END) {
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

int getop(char s[], char input[], size_t len) {
  int c, i;
  int type;

  while ((s[0] = c = input[line_counter++]) == ' ' || c == '\t')
    ;
  s[1] = '\0';
  if (c == '\n')
    return END;
  if (isalpha(c))
    return LETTER;
  if (!isdigit(c) && c != '.')
    return c;

  i = 0;
  if (isdigit(c))
    while (isdigit(s[++i] = c = input[line_counter++]))
      ;
  if (c == '.')
    while (isdigit(s[++i] = c = input[line_counter++]))
      ;
  s[i] = '\0';

  if (c != EOF)
    --line_counter;

  return NUMBER;
}
