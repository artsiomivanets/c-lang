#include <stdio.h>
/* print Fahrenheit-Celsius table
   for fahr = 0, 20, ..., 300; floating-point version */

void print_border() { printf(" ---- --------\n"); }

float convert_fahr_to_celsius(float fahr) {
  return (5.0 / 9.0) * (fahr - 32.0);
};

int main() {
  float fahr, celsius;
  float lower, upper, step;

  lower = 0;   /* lower limit of temperatuire scale */
  upper = 300; /* upper limit */
  step = 20;   /* step size */

  fahr = lower;

  printf("|%s| %s|\n", "fahr", "celsius");
  print_border();
  while (fahr <= upper) {
    celsius = convert_fahr_to_celsius(fahr);
    printf("|%4.0f|%8.1f|\n", fahr, celsius);
    print_border();
    fahr = fahr + step;
  }
}

/*
|fahr| celsius|
 ---- --------
|   0|   -17.8|
 ---- --------
|  20|    -6.7|
 ---- --------
|  40|     4.4|
 ---- --------
|  60|    15.6|
 ---- --------
|  80|    26.7|
 ---- --------
| 100|    37.8|
 ---- --------
| 120|    48.9|
 ---- --------
| 140|    60.0|
 ---- --------
| 160|    71.1|
 ---- --------
| 180|    82.2|
 ---- --------
| 200|    93.3|
 ---- --------
| 220|   104.4|
 ---- --------
| 240|   115.6|
 ---- --------
| 260|   126.7|
 ---- --------
| 280|   137.8|
 ---- --------
| 300|   148.9|
 ---- --------
 */
