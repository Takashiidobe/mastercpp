#include <float.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("FLOAT_SIZE: %d byte(s)\n", sizeof(float));
  printf("FLOAT_MIN: %e\n", FLT_MIN);
  printf("FLOAT_MAX: %e\n", FLT_MAX);
}
