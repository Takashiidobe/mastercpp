#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("USHORT_SIZE: %d byte(s)\n", sizeof(unsigned short));
  printf("USHORT_MIN: %hd\n", USHRT_MAX + 1);
  printf("USHORT_MAX: %d\n", USHRT_MAX);
}
