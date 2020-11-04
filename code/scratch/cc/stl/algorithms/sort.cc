#include <algorithm>
#include <iostream>
#include <ranges>

int main() {
  std::vector vec = {6, 5, 4, 3, 2, 1};
  std::ranges::sort(vec);

  for (const auto item : vec) {
    std::cout << "The current element is: " << item << '\n';
  }

  const auto is_sorted = std::ranges::is_sorted(vec);

  std::cout << std::boolalpha << "is the collection sorted: " << is_sorted
            << '\n';
}
