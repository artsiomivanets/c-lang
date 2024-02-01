#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

int main() {
  float fahr, celsius;

  printf("%s | %s\n", "fahr", "celsius");

  for (fahr = UPPER; fahr >= LOWER; fahr = fahr - STEP) {
    celsius = (5.0 / 9.0) * (fahr - 32.0);
    printf("%4.0f | %7.1f\n", fahr, celsius);
  }
}

/*
fahr | celsius
 300 |   148.9
 280 |   137.8
 260 |   126.7
 240 |   115.6
 220 |   104.4
 200 |    93.3
 180 |    82.2
 160 |    71.1
 140 |    60.0
 120 |    48.9
 100 |    37.8
  80 |    26.7
  60 |    15.6
  40 |     4.4
  20 |    -6.7
   0 |   -17.8
 */
