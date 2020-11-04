# Ranges

C++20 adds a new feature called ranges.

In old C++, to sort a collection, you might try:

```cpp
#include <algorithm>
#include <vector>

int main() {
  auto vec = std::vector{4,5,6,1,3,2};
  std::sort(vec.begin(), vec.end());
}
```

Now you don't have to provide the begin and the end, and can sort using the ranges version of sort, which has a begin and end.

```cpp
#include <algorithm>
#include <ranges>
#include <vector>

int main() {
  auto vec = std::vector{4,5,6,1,3,2};
  std::ranges::sort(vec);
}
```
