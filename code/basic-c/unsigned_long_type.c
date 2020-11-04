#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("ULONG_SIZE: %d byte(s)\n", sizeof(unsigned long));
  printf("ULONG_MIN: %lu\n", ULONG_MAX + 1);
  printf("ULONG_MAX: %lu\n", ULONG_MAX);
}
