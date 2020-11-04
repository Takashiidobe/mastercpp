#include <iostream>

struct Resource {
  int res;
  Resource(int _res) { res = _res; }
};

int main() {
  auto ptr = new Resource(10);  // dynamically allocate Resource

  if (ptr->res == 10) {
    std::cout << "Res is 10!" << '\n';
    delete ptr;
    // delete ptr before return
    return 0;
  }

  delete ptr;  // unreachable.
}
