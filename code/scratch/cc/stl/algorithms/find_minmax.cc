#include <algorithm>
#include <iostream>
#include <ranges>

int main() {
  const std::vector vec = {5, 6, 10, 2, 3, 1};
  const auto [min_item, max_item] = std::ranges::minmax(vec);

  std::cout << "The max element is: " << max_item << '\n';
  std::cout << "The min element is: " << min_item << '\n';
  ;
}
