#include <stdio.h>

void print_nums() {
  int num = 0;
  static int static_num = 0;

  num += 10;
  static_num += 10;

  printf("num is: %d, static_num is: %d\n", num, static_num);
}

int main() {
  for (int i = 0; i < 10; i++) print_nums();
}
