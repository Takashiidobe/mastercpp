# Smart Pointers

Smart pointers are a class that manage a dynamically allocated object for you.

Imagine this scenario.

```cpp
#include <fmt/core.h>

struct Resource {
  int res;
  Resource(int _res) { res = _res; }
  ~Resource() { fmt::print("Destructor successfully ran."); }
};

int main() {
  auto ptr = new Resource(10); // dynamically allocate Resource

  if (ptr->res == 10) {
    fmt::print("Res is 10!\n");
    return 0;
  } // the program terminates here, so we never delete ptr.

  delete ptr; // unreachable.
}
```

Here, we forget to delete ptr, because we throw and terminate the program. This leaks memory.

We can fix this by deleting ptr before we throw.

```cpp
struct Resource {
  int res;
  Resource(int _res) { res = _res; }
  ~Resource() { fmt::print("Destructor successfully ran."); }
};

int main() {
  auto ptr = new Resource(10); // dynamically allocate Resource

  if (ptr->res == 10) {
    fmt::print("Res is 10!\n");
    delete ptr;
    // delete ptr before return
    return 0;
  }

  delete ptr; // unreachable.
}
```

In the case that we check resource in many blocks, it's easy to forget to delete ptr.

```cpp
struct Resource {
  int res;
  Resource(int _res) { res = _res; }
  ~Resource() { fmt::print("Destructor successfully ran."); }
};

int main() {
  auto ptr = new Resource(9); // dynamically allocate Resource

  if (ptr->res == 10) {
    fmt::print("Res is 10!\n");
    delete ptr;
    return 0;
  } else if (ptr->res > 10) {
    fmt::print("Res is greater than 10!\n");
    delete ptr;
    return 1;
  } else {
    // forgot to delete pointer here.
    fmt::print("Res is less than 10!\n");
    return -1;
  }

  delete ptr; // unreachable.
}
```

Smart pointers help us here by _automatically_ deleting memory when the smart pointer goes out of scope.

Unique pointers are created by calling the function `std::make_unique<Type>` with the arguments forwarded to the constructor.

```cpp
#include <fmt/core.h>
#include <memory>

struct Resource {
  int res;
  Resource(int _res) { res = _res; }
  ~Resource() { fmt::print("Destructor successfully ran."); }
};

int main() {
  auto ptr = std::make_unique<Resource>(9); // dynamically allocate Resource

  if (ptr->res == 10) {
    fmt::print("Res is 10!\n");
    return 0;
  } else if (ptr->res > 10) {
    fmt::print("Res is greater than 10!\n");
    return 1;
  } else {
    fmt::print("Res is less than 10!\n");
    return -1;
  } // destructor runs here.
}
```

Now your memory will be destroyed when it goes out of scope.
