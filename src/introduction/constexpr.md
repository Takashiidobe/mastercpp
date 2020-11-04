# Constexpr

What happens if we want a computed property to be calculated at compile time?
We can use constexpr for this.

```cpp
const double PI = 22 / 7; // this works

constexpr auto calculate_pi() {
  return 22.0 / 7;
}

constexpr double PI = calculate_pi();
```
