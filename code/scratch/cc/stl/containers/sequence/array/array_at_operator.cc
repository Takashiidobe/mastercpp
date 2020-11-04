#include <array>
#include <iostream>

int main() {
  std::array arr = {1, 2, 3, 4, 5};
  std::cout << "the first element is: " << arr.at(0);  // prints 1
  // set the first element to 0.
  arr.at(0) = 0;
  std::cout << "the first element is now: " << arr.at(0);  // prints 0.

  try {
    arr.at(5) = 6;
  } catch (std::out_of_range const& e) {
    std::cout << e.what();  // prints exception
  }
}
