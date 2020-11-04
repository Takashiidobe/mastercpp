# Algorithms

The STL (Standard Template Library) is one of the killer features of C++; its collection of Data Structures and Algorithms make C++ great in the general case. We'll be discussing some of the algorithms here:

`Sort`.

```cpp
#include <fmt/core.h>
#include <algorithm>
#include <ranges>

int main() {
  std::vector vec = {6, 5, 4, 3, 2, 1};
  std::ranges::sort(vec);

  for (const auto item: vec) {
    fmt::print("The current element is: {}.\n", item);
  }

  const auto is_sorted = std::ranges::is_sorted(vec);

  fmt::print("is the collection sorted: {}", is_sorted);
}
```

`Find Max/Find min`

```cpp
#include <fmt/core.h>
#include <algorithm>
#include <ranges>

int main() {
  const std::vector vec = {5, 6, 10, 2, 3, 1};
  const auto max_item = std::ranges::max(vec);
  const auto min_item = std::ranges::min(vec);

  fmt::print("The max element is: {}\n", max_item);
  fmt::print("The min element is: {}\n", min_item);
}
```

```cpp
#include <fmt/core.h>
#include <algorithm>
#include <ranges>

int main() {
  const std::vector vec = {5, 6, 10, 2, 3, 1};
  const auto [min_item, max_item] = std::ranges::minmax(vec);

  fmt::print("The max element is: {}\n", max_item);
  fmt::print("The min element is: {}\n", min_item);
}
```

Binary Search to find an element in a sorted set:

```cpp
#include <fmt/core.h>
#include <algorithm>
#include <ranges>

int main() {
  const std::vector vec = {1,2,5,6,10};
  const auto b = std::ranges::binary_search(vec, 6);
  fmt::print("{}", b);
}
```
