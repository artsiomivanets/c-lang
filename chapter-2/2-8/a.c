#include <stdio.h>

unsigned char rightrot(unsigned char x, int n) {
  char size, mask, right_bits_mask, right_bits, left_bits, left_bits_mask;
  size = sizeof(unsigned char) * 8;

  left_bits_mask = ~(~0 << n);

  left_bits = (left_bits_mask & x) << (size - n);
  right_bits = x >> n;

  return left_bits | right_bits;
}

int main() { printf("%d", rightrot(136, 4)); }
