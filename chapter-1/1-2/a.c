#include <stdio.h>

int main() {
  printf("hello");
  printf("\c");
  printf("world\n");
}

/*
 * ANSWER:
    a.c: In function ‘main’:
    a.c:5:14: warning: unknown escape sequence: '\c'
    5 |   printf("\c");
      |              ^

 */
