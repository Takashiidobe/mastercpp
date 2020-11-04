#include <iostream>
#include <memory>

struct Resource {
  int res;
  Resource(int _res) { res = _res; }
  ~Resource() { std::cout << "Destructor successfully ran." << '\n'; }
};

int main() {
  auto ptr = std::make_unique<Resource>(9);  // dynamically allocate Resource

  if (ptr->res == 10) {
    std::cout << "Res is 10!" << '\n';
    return 0;
  } else if (ptr->res > 10) {
    std::cout << "Res is greater than 10!" << '\n';
    return 1;
  } else {
    std::cout << "Res is less than 10!" << '\n';
    return -1;
  }  // destructor runs here.
}
