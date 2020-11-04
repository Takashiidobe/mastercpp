#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("LLONG_SIZE: %d byte(s)\n", sizeof(long long));
  printf("LLONG_MIN: %ld\n", LLONG_MIN);
  printf("LLONG_MAX: %ld\n", LLONG_MAX);
}
