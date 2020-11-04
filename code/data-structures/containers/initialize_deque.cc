#include <deque>
#include <iostream>

int main() {
  std::deque<int> d = {7, 5, 16, 8};

  // add to the front of the deque
  d.push_front(13);
  // add to the back of the deque
  d.push_back(25);

  // Iterate and print values of deque
  for (const auto n : d) {
    std::cout << n << '\n';
  }
}
