#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

int main() {
  printf("%d", getchar() == EOF);
  printf("\n");
}

/*
  Any char is 0 like:

  gcc a.c && ./a.out
  1
  0

  But Ctrl+d is EOF patter so

  gcc a.c && ./a.out
  1

  we see when type Ctrl+d

 */
