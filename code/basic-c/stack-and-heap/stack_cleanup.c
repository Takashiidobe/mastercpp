#include <stdio.h>

int main() {
  {
    int times = 10;
    char *slogan = "Hi";

    for (int i = 0; i < times; i++)
      printf("%s\n", slogan);
  }

  times = 20; // this fails to compile because the variable is gone.
}
