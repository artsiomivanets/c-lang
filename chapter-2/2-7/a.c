#include <stdio.h>

unsigned invert(unsigned x, int p, int n) {
  int left_bits, right_bits, without_range, inverted_range;
  left_bits = (x >> (p + 1) << (p + 1));
  right_bits = (x & ~(~0 << (p + 1 - n)));
  without_range = left_bits | right_bits;
  inverted_range = ~x & (~(~0 << n) << (p + 1 - n));
  return inverted_range | without_range;
}

int main() { printf("%d", invert(145, 0, 1)); }
