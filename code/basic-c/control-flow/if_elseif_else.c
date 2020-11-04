#include <stdio.h>

int main() {
  int apples = 3;

  if (apples > 5) {
    printf("You have a lot of apples!\n");
  } else if (apples > 0) {
    printf("You have a few apples.\n");
  } else {
    printf("You have no apples.\n");
  }
}
