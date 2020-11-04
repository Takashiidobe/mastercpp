#include <algorithm>
#include <ranges>
#include <vector>

int main() {
  std::vector vec = {4, 5, 6, 1, 3, 2};
  std::ranges::sort(vec);
}
