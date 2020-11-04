#include <tuple>  // include the tuple header for tuple related functions

int main() {
  std::tuple<int, std::string> t = {5, "hi"};
  // destructure the first element into the variable first, and the second
  // element into the variable second.
  const auto [first, second] = t;

  std::cout << "first: " << first << " second: " << second << '\n';
}
