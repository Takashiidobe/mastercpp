#include <algorithm>
#include <iostream>
#include <ranges>

int main() {
  const std::vector vec = {5, 6, 10, 2, 3, 1};
  const auto max_item = std::ranges::max(vec);
  const auto min_item = std::ranges::min(vec);

  std::cout << "The max element is: " << max_item;
  std::cout << "The min element is: " << min_item;
}
