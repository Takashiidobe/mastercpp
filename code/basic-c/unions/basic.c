#include <stdio.h>

int main() {
  union num {
    float f;
    int i;
  };

  union num number;
  number.i = 10;

  printf("%d\n", number.i);
}
