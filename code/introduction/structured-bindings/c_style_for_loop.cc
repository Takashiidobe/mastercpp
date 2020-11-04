#include <iostream>
#include <vector>

int main() {
  std::vector vec = {1, 2, 3, 4};
  for (std::size_t i = 0; i < 4; i++) {
    std::cout << "My value is: " << vec[i] << '\n';
  }
}
