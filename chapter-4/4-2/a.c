#include <ctype.h>
#include <stdio.h>

double atof(char s[]);
int getstate(char i);

int main() {
  printf("%lf\n", atof("123.45e-6"));
  printf("%lf\n", atof("123.45e+6"));
  printf("%lf\n", atof("123.45E-6"));
  return 0;
}

/* atof: convert string s to double */
double atof(char s[]) {
  double val, power, e, result;
  int i, sign, esign;
  for (i = 0; isspace(s[i]); i++) /* skip white space */
    ;
  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-')
    i++;
  for (val = 0.0; isdigit(s[i]); i++)
    val = 10.0 * val + (s[i] - '0');
  if (s[i] == '.')
    i++;
  for (power = 1.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
    power *= 10;
  }
  if (s[i] == 'e' || s[i] == 'E')
    i++;
  esign = s[i++];
  for (e = 0.0; isdigit(s[i]); i++) {
    e = 10.0 * e + (s[i] - '0');
  }
  result = sign * val / power;
  while (e > 0) {
    if (esign == '-') {
      result /= 10.0;
    } else {
      result *= 10.0;
    }
    e--;
  }
  return result;
}
