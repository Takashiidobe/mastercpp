#include <iostream>
#include <vector>

int main() {
  std::vector vec = {1, 2, 3, 4};
  for (std::size_t i = {0}; const int item : vec) {
    std::cout << "My index is: " << i << '\n';
    std::cout << "My value is: " << item << '\n';
    i++;
  }
}
