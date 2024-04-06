#include "../lines/a.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void mqsort(int v[], int left, int right);
void swap(void *v[], int i, int j);
int numcmp(const char *s1, const char *s2);
void myqsort(void *lineptr[], int left, int right, int (*comp)(void *, void *));
int numcmp(const char *, const char *);
int main(int argc, char *argv[]) {
  int nlines;      /* number of input lines read */
  int numeric = 0; /* 1 if numeric sort */
  if (argc > 1 && strcmp(argv[1], "-n") == 0)
    numeric = 1;
  if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
    myqsort((void **)lineptr, 0, nlines - 1,
            (int (*)(void *, void *))(numeric ? numcmp : strcmp));
    writelines(lineptr, nlines);
    return 0;
  } else {
    printf("input too big to sort\n");
    return 1;
  }
}
void myqsort(void *v[], int left, int right, int (*comp)(void *, void *)) {
  int i, last;
  void swap(void *v[], int, int);
  if (left >= right) /* do nothing if array contains */
    return;          /* fewer than two elements */
  swap(v, left, (left + right) / 2);
  last = left;
  for (i = left + 1; i <= right; i++)
    if ((*comp)(v[i], v[left]) < 0)
      swap(v, ++last, i);
  swap(v, left, last);
  myqsort(v, left, last - 1, comp);
  myqsort(v, last + 1, right, comp);
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
