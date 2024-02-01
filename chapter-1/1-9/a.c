#include <stdio.h>

#define BLANK ' '

int main() {
  int c, prev;

  while ((c = getchar()) != EOF) {
    if ((c == BLANK && prev == BLANK))
      continue;
    prev = c;
    putchar(c);
  }
}

/*
  $ gcc a.c && ./a.out
  w   w   w
  w w w

  $ gcc a.c && ./a.out
  wwwerwerwerwerwer                  werwerwerwerwrwer
  wwwerwerwerwerwer werwerwerwerwrwer

  $ gcc a.c && ./a.out
                w w
   w w
 */
