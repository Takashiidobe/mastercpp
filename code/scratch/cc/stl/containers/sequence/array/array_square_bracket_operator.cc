#include <array>
#include <iostream>

int main() {
  std::array arr = {1, 2, 3, 4, 5};

  std::cout << "the first element is: " << arr[0];  // prints 1
  // set the first element to 0.
  arr[0] = 0;
  std::cout << "the first element is now: " << arr[0];  // prints 0.

  // arr[5] and above or arr[-1] will trigger undefined behavior! Be Careful!
}
