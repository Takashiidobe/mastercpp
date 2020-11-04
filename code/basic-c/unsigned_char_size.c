#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("UNSIGNED_CHAR_SIZE: %d byte(s)\n", sizeof(unsigned char));
  printf("UNSIGNED_CHAR_MAX: %hhu\n", UCHAR_MAX);
  printf("UNSIGNED_CHAR_MIN: %hhu\n", UCHAR_MAX + 1);
  return 0;
}
