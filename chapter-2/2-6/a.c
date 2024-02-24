#include <stdio.h>

int get_mask(unsigned x, int p, int n) {
  int right_shift = p + 1;
  int take_left_bits = right_shift - n;
  return ~(x >> right_shift << right_shift) >> take_left_bits << take_left_bits;
}

unsigned setbits(unsigned x, int p, int n, int y) {
  if (y) {
    return x | get_mask(~0, p, n);
  } else {
    return x & ~get_mask(x, p, n);
  }
}

int main() { printf("%d", setbits(0, 1, 2, 1)); }
