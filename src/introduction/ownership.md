# Ownership

Ownership is a concept that comes up in programming sometimes. In an unmanaged programming language (one without a garbage collector, like C++), it loosely means who has to free memory after it is no longer in use.

In this example, what happens?

```cpp
#include <fmt/core.h>

int main() {
  int x = 5;
  fmt::print(x);
}
```

This program allocates a variable `x` with a value of `5` onto the stack, and prints it out. After printing out the variable, the variable `x` leaves scope and is cleaned up automatically. **Any variables on the stack are cleaned up automatically**.

What happens here?

```cpp
#include <fmt/core.h>

int main() {
  int *x = new int;
  *x = 5;
  fmt::print("{}", *x);
}
```

Here we allocate a pointer on the stack to a integer on the heap, and set the value of it to 5. Since the stack is a managed resource, it is automatically taken care of. However, the heap is not something we own. Therefore, we have to tell the heap that we no longer want it again.

This is normally done with a "delete" statement, which this program fails to do. Thus, the pointer on the stack is collected, but the heap memory is never told to be collected. The memory is leaked on the heap, and never freed. We can fix this in this case by deleting the variable after we're done with it:

```cpp
#include <fmt/core.h>

int main() {
  int *x = new int;
  *x = 5;
  fmt::print("{}", *x);
  delete x;
}
```

Consider a more complicated example:

```cpp
#include <fmt/core.h>

void print_int(int *x) {
  fmt::print("{}", *x);
}

void increment_int_and_delete(int *x) {
  *x = *x + 1;
  delete x;
}

int main() {
  int *x = new int;
  *x = 5;
  increment_int_and_delete(*&x);
  print_int(*&x);
}
```

As before, we create a pointer on the stack that points to the heap with a value of 5, and then we increment the value of the heap value before deleting it. Then, we try to print it.
Of course, we've deleted memory and then tried to use it, which is a `use after free`. This is `undefined behavior`, so don't do this.

The problem here is that raw pointers do not convey ownership. You can signal it in the function (I changed the name from `increment_int` to `increment_int_and_delete`) so the user knows that this int is deleted, but you could also pass the function a `nullptr`, which it would then try to delete.

In this example, the caller passes a nullptr (which compiles), and then tries to print `x`. This results in `undefined behavior` because we try to print the `nullptr`.

```cpp
#include <fmt/core.h>

void print_int(int *x) {
  fmt::print("{}", *x);
}

void increment_int_and_delete(int *x) {
  *x = *x + 1;
  delete x;
}

int main() {
  int *x = new int;
  *x = 5;
  increment_int(nullptr); // ???
  print_int(*&x);
  // x is leaked here since no one deleted it.
}
```

The problem here is twofold; pointers can always be `nullptr`, so you must check for that case beforehand:

```cpp
void increment_int_and_delete(int *x) {
  if (x != nullptr) {
    *x = *x + 1;
    delete x;
  }
}
```

Secondly, pointers do not convey ownership: in the case of `increment_int_and_delete`, we want to take ownership of the pointer that is passed in and delete it after we're done with it. This function takes ownership of the passed in pointer, but the way we would signal a non-owning function is exactly the same -- which leads to problems like deleting memory we shouldn't, or leaking memory because no one believes they have ownership over memory.

```cpp
// exactly the same function signature
void increment_int_and_delete(int *x) {
  if (x != nullptr) {
    *x = *x + 1;
  }
}
```
