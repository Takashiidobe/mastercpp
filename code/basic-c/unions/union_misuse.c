#include <stdio.h>

int main() {
  union num {
    float d;
    int i;
  };

  union num number;
  number.i = 10;
  number.d = 5.0;

  printf("%d\n", number.i);
}
