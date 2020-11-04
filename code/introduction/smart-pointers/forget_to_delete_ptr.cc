#include <iostream>

struct Resource {
  int res;
  Resource(int _res) { res = _res; }
  ~Resource() { std::cout << "Destructor successfully ran." << '\n'; }
};

int main() {
  auto ptr = new Resource(9);  // dynamically allocate Resource

  if (ptr->res == 10) {
    std::cout << "Res is 10!" << '\n';
    delete ptr;
    return 0;
  } else if (ptr->res > 10) {
    std::cout << "Res is greater than 10!" << '\n';
    delete ptr;
    return 1;
  } else {
    // forgot to delete pointer here.
    std::cout << "Res is less than 10!" << '\n';
    return -1;
  }

  delete ptr;  // unreachable.
}
