# Auto

The `auto` keyword allows for type inference. In general, this keyword tells the compiler to figure out the type it refers to.

This can come in handy when you have a long type declaration on both sides.

```cpp
std::map<std::string, std::vector<int>> map_of_string_to_vec =
  std::map<std::string, std::vector<int>>{{"hi", {1, 2, 3, 4}}};

auto map_of_string_to_vec_2 =
  std::map<std::string, std::vector<int>>{{"hi", {1, 2, 3, 4}}};
```

Auto also defaults to certain types if it can infer it:

For example:

```cpp
auto d = 5.0; // double, just like writing double d = 5.0;

auto i = 1; // int, just like writing int i = 1;
```

Generally auto infers the type of numbers with a decimal point to be `double`, and integers to be `int`.

Perhaps surprisingly, auto infers string literals to be `const char[length + 1]`, instead of std::string.

```cpp
auto s = "Hello" // const char[6]
```

To make C++ infer a string, you can import an operator overload on `const char[]s` to make auto interpret them as a string by importing the `<string>` header, writing `using std::string_literals::operator""s`, and suffixing the string after auto with an s.

```cpp
#include <fmt/core.h>
#include <iostream>
#include <string>

using std::string_literals::operator""s;

int main() {
  auto s = "Hello"s;
  s += " World"; // use string concatenation
  fmt::print(s);
}
```

Function type inference:

Auto can also be used to infer the return type of a function.

```cpp
auto concatenate(std::string left, std::string right) {
  return left + right;
}
```

Since the function above concatenates and returns two std::strings, it must return a std::string, which auto infers for us.

Trailing return type syntax:

You can append the type of auto after the function.

```cpp
auto concatenate(std::string left, std::string right) -> std::string {
  return left + right;
}

int add(int left, int right) -> int {
  return left + right;
}
```

In this case, we don't gain anything outside of having our functions line up.

However, with the trailing return syntax, we can use a decltype of our templated arguments to return the proper type of an item, which would previously not be possible.

```cpp
template<typename Container, typename Index>
auto get_item(Container& c, Index i) -> decltype(c[i]) {
  return c[i];
}
```
