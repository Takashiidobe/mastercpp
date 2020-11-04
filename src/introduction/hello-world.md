# Hello World

We're going to assume some passing familiarity with a programming language of your choice. As long as you know the basics, you should be fine. That being said, we won't teach you C++ from nothing. For that we recommend [LearnCpp](https://www.learncpp.com/) which this site is loosely based off of.

```cpp,editable
{{#include ../../code/introduction/hello_world.cc}}
```

Let's analyze this.

`#include` includes the code in a header file for the program to use. We use the functions `std::cout` and `std::endl` from this header file.

```cpp,editable
{{#include ../../code/introduction/hello_world.cc:1}}
```

`int main() {}` is the body which defines the `main` function. Currently the main function takes no arguments, although we may allow our program to take some later on.

`std::cout << "Hello World"` can roughly be roughly thought of as giving "Hello World" to `std::cout`.

`return 0;` returns the exit code and ends the main function. In general, if `main` ran successfully (without problems) it returns an exit code of `0`. If there are any errors, you can return a different number, but generally 0-255 are the common exit codes. This is unnecessary, so we'll skip this in later programs.
