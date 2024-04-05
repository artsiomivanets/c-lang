#include "./calc.c"
#include <stdio.h>

void expr(char *s, char *t, int n);

int main(int argc, char *argv[]) {
  char **params_pointer = argv + 1;
  while (*params_pointer)
    put_to_buff(**params_pointer++), put_to_buff(' ');
  reset_buff();
  calc();
  return 0;
}
