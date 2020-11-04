#include <iostream>

int main() {
  int *x = new int;
  *x = 5;
  std::cout << *x << '\n';
}
