#include <float.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("LDOUBLE_SIZE: %d byte(s)\n", sizeof(long double));
  printf("LDOUBLE_MIN: %Lf\n", LDBL_MIN);
  printf("LDOUBLE_MAX: %Lf\n", LDBL_MAX);
}
