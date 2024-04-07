#include "../lines/a.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mqsort(int v[], int left, int right);
void swap(void *v[], int i, int j);
int numcmp(const char *s1, const char *s2);
void myqsort(void *lineptr[], int left, int right, int (*comp)(void *, void *),
             int (* or)(int));
int numcmp(const char *, const char *);
int order(int);
int reorder(int);
int contains(char **lineptr, char *substr, int amount);

int main(int argc, char *argv[]) {
  int nlines;
  int numeric = 0;
  int reverse = 0;
  if (contains(argv, "-n", argc))
    numeric = 1;
  if (contains(argv, "-r", argc))
    reverse = 1;
  if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
    myqsort((void **)lineptr, 0, nlines - 1,
            (int (*)(void *, void *))(numeric ? numcmp : strcmp),
            (int (*)(int))(reverse ? reorder : order));
    writelines(lineptr, nlines);
    return 0;
  } else {
    printf("input too big to sort\n");
    return 1;
  }
}

int contains(char **lineptr, char *substr, int amount) {
  for (int n = 0; n < amount; n++) {
    if (strcmp(*(lineptr + n), substr) == 0)
      return 1;
  }
  return 0;
}
int order(int result) { return result < 0; }
int reorder(int result) { return result > 0; };

void myqsort(void *v[], int left, int right, int (*comp)(void *, void *),
             int (* or)(int)) {
  int i, last;
  void swap(void *v[], int, int);
  if (left >= right) /* do nothing if array contains */
    return;          /* fewer than two elements */
  swap(v, left, (left + right) / 2);
  last = left;
  for (i = left + 1; i <= right; i++)
    if ((* or)(((*comp)(v[i], v[left]))))
      swap(v, ++last, i);
  swap(v, left, last);
  myqsort(v, left, last - 1, comp, or);
  myqsort(v, last + 1, right, comp, or);
}

int numcmp(const char *s1, const char *s2) {
  double v1, v2;
  v1 = atof(s1);
  v2 = atof(s2);
  if (v1 < v2)
    return -1;
  else if (v1 > v2)
    return 1;
  else
    return 0;
}

void swap(void *v[], int i, int j) {
  void *temp;
  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}
