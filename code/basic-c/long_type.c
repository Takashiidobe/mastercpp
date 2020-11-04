#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("LONG_SIZE: %d byte(s)\n", sizeof(long));
  printf("LONG_MIN: %ld\n", LONG_MIN);
  printf("LONG_MAX: %ld\n", LONG_MAX);
}
