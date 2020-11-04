#include <algorithm>
#include <iostream>
#include <ranges>

int main() {
  const std::vector vec = {1, 2, 5, 6, 10};
  const auto b = std::ranges::binary_search(vec, 6);
  std::cout << b << '\n';
}
