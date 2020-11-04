#include <iostream>
#include <vector>

int main() {
  std::vector vec = {1, 2, 3, 4};
  for (const int item : vec) {
    std::cout << "My value is: " << item << '\n';
  }
}
