#include <stdio.h>

int main() {
  char hello[5] = "hello";
  hello[0] = 'a';
  printf("%s\n", hello);
}
