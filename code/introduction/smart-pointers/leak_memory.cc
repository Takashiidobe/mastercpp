#include <iostream>

struct Resource {
  int res;
  Resource(int _res) { res = _res; }
};

int main() {
  auto ptr = new Resource(10);  // dynamically allocate Resource

  if (ptr->res == 10) {
    std::cout << "Res is 10!" << '\n';
    return 0;
  }  // the program terminates here, so we never delete ptr.

  delete ptr;  // unreachable.
}
