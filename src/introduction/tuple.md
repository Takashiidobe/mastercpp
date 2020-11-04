# Tuples

The tuple is a data structure that can hold different types of elements, unlike a vector or array, which can only hold the elements of the same type.

## Initialization

```cpp,editable
#include <tuple> // include the tuple header for tuple related functions
std::tuple<int, std::string> t = {5, "hi"};
const auto [first, second] = t; // destructure the first element into the variable first, and the second element into the variable second.
```
