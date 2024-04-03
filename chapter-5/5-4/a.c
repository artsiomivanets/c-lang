#include <ctype.h>
#include <stdio.h>
#include <string.h>

int strend(char *s, char *t);

int main() {
  int result;
  char *str1 = "hello world!";
  char *str2 = "world!";
  result = strend(str1, str2);
  printf("contains: %d\n", result);
  return 0;
}

int strend(char *s, char *t) {
  int len_s, len_t, n;
  char *start_of_end_of_s;
  len_s = strlen(s);
  len_t = strlen(t);

  start_of_end_of_s = s + (len_s - len_t);
  while (*start_of_end_of_s == *t && *t != '\0')
    t++, start_of_end_of_s++;
  if (*start_of_end_of_s == '\0')
    return 1;
  else
    return 0;
}
