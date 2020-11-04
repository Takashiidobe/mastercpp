# Structured Bindings

The venerable C style for loop gives one a lot of control in how to loop. You can loop forwards, backwards, increment your counter variable any amount, decrement it any amount, or do nothing. But most of the time we don't need that control; we just want to be able to do something for every item in a collection.

```cpp
#include <fmt/core.h>
#include <vector>

int main() {
  std::vector vec = {1, 2, 3, 4};
  for (std::size_t i = 0; i < 4; i++) {
    fmt::print("My value is: {}\n", vec[i]));
  }
}
```

And this works fine. But we might mistype something.

```cpp
#include <fmt/core.h>
#include <vector>

int main() {
  std::vector vec = {1, 2, 3, 4};
  for (std::size_t i = 0; i <= 4; i++) {
    fmt::print("My value is: {}\n", vec[i]);
  }
}
```

Oops. Out of bounds access. We're asking the vector for its fifth element when it only has four. What we really mean to say is "print out the value for every item in the array."

Enter the `For Each` loop.

Now I will never have an out of bounds access!

```cpp
#include <fmt/core.h>
#include <vector>

int main() {
  std::vector vec = {1, 2, 3, 4};
  for (const int item : vec) {
    std::puts(fmt::print("My value is: {}\n", item));
  }
}
```

But what if I want the index, which comes in handy sometimes? I can initialize i to be 0, and increment it at the end of the block. Now i is captured inside of the for loop, and doesn't leak outside.

```cpp
#include <fmt/core.h>
#include <vector>

int main() {
  std::vector vec = {1, 2, 3, 4};
  for (std::size_t i = {0}; const int item : vec) {
    fmt::print("My index is: {}\n", i);
    fmt::print("My value is: {}\n", item);
    i++;
  }
}
```
