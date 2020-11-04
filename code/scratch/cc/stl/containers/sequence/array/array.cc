#include <array>
#include <iostream>

int main() {
  std::array arr = {1, 2, 3, 4, 5};

  for (const auto item : arr) {
    std::cout << item << '\n';
  }
}
