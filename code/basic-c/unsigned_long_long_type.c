#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("ULLONG_SIZE: %d byte(s)\n", sizeof(unsigned long long));
  printf("ULLONG_MIN: %llu\n", ULLONG_MAX + 1);
  printf("ULLONG_MAX: %llu\n", ULLONG_MAX);
}
