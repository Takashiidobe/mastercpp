#include <float.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("DOUBLE_SIZE: %d byte(s)\n", sizeof(double));
  printf("DOUBLE_MIN: %e\n", DBL_MIN);
  printf("DOUBLE_MAX: %e\n", DBL_MAX);
}
