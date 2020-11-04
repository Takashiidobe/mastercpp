#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("CHAR_SIZE: %d byte(s)\n", sizeof(char));
  printf("CHAR_MAX: %d\n", CHAR_MAX);
  printf("CHAR_MIN: %d\n", CHAR_MIN);
  return 0;
}
