#include <iostream>

int main() {
  enum class Color : char { Blue = 'b', Red = 'r', Green = 'g' };
  std::cout << Color::Blue << '\n';  // prints 'b' for Blue.
}
