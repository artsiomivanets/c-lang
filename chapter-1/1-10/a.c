#include <stdio.h>

int main() {
  int c;
  while ((c = getchar()) != EOF) {
    if (c == '\t') {
      putchar('\\');
      putchar('t');
    } else if (c == '\b') {
      putchar('\\');
      putchar('b');
    } else if (c == '\\') {
      putchar('\\');
      putchar('\\');
    } else {
      putchar(c);
    }
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
