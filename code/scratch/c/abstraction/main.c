#include <stdio.h>

#include "library.h"

int main() {
  printf("%d\n", private());  // private cannot be called.
  printf("%d\n", public());
}
