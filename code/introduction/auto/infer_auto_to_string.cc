#include <iostream>
#include <string>

using std::string_literals::operator""s;

int main() {
  auto s = "Hello"s;
  s += " World";  // use string concatenation
  std::cout << s << '\n';
}
