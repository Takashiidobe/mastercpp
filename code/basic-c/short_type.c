#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("SHORT_SIZE: %d byte(s)\n", sizeof(short));
  printf("SHORT_MIN: %hd\n", SHRT_MIN);
  printf("SHORT_MAX: %hd\n", SHRT_MAX);
}
