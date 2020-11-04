#include <iostream>

void print_int(int *x) { std::cout << *x << '\n'; }

void increment_int_and_delete(int *x) {
  *x = *x + 1;
  delete x;
}

int main() {
  int *x = new int;
  *x = 5;
  increment_int_and_delete(nullptr);  // ???
  print_int(*&x);
  // x is leaked here since no one deleted it.
}
