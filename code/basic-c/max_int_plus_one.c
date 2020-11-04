#include <limits.h>
#include <stdio.h>

int main() {
  int overflown_number = INT_MAX + 1;

  printf("%d\n", overflown_number);
}
