# Array

Array:

The array is much like a C-style array, but it doesn't decay to a pointer, but with a similar API to the rest of the STL containers.

```cpp
#include <array>
#include <fmt/core.h>

int main() {
  std::array arr = {1,2,3,4,5};

  for (const auto item: arr) {
    fmt::print("{}\n", item);
  }
}
```

Arrays are a fixed size, so there are no operators which can grow or shrink an array.

You have a few methods on the class itself, as well as some constructors that are useful.

At:

`At` returns or sets the item in the array with bounds checking (if you ask for an index which is not in the array, you get a std::out_of_range exception).

```cpp
#include <array>
#include <fmt/core.h>

int main() {
  std::array arr = {1,2,3,4,5};
  fmt::print("the first element is: {}", arr.at(0)); // prints 1
  // set the first element to 0.
  arr.at(0) = 0;
  fmt::print("the first element is now: {}", arr.at(0)); // prints 0.

  try {
    arr.at(5) = 6;
  } catch (std::out_of_range const& e) {
    fmt::print("{}", e.what()); // prints exception
  }
}
```

Operator[]:

`operator[]` is like `at`, but without bounds checking. If you ask for an index which is not in the array, undefined behavior occurs.

```cpp
#include <array>
#include <fmt/core.h>

int main() {
  std::array arr = {1,2,3,4,5};

  fmt::print("the first element is: {}", arr[0]); // prints 1
  // set the first element to 0.
  arr[0] = 0;
  fmt::print("the first element is now: {}", arr[0]); // prints 0.

  // arr[5] and above or arr[-1] will trigger undefined behavior! Be Careful!
}
```
