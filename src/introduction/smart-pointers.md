# Smart Pointers

Smart pointers are a class that manage a dynamically allocated object for you.

Imagine this scenario.

```cpp,editable
{{#include ../../code/introduction/smart-pointers/leak_memory.cc}}
```

Here, we forget to delete ptr, because we throw and terminate the program. This leaks memory.

We can fix this by deleting ptr before we throw.

```cpp,editable
{{#include ../../code/introduction/smart-pointers/manually_delete_ptr.cc}}
```

In the case that we check resource in many blocks, it's easy to forget to delete ptr.

```cpp,editable
{{#include ../../code/introduction/smart-pointers/forgot_to_delete_ptr.cc}}
```

Smart pointers help us here by _automatically_ deleting memory when the smart pointer goes out of scope.

Unique pointers are created by calling the function `std::make_unique<Type>` with the arguments forwarded to the constructor.

```cpp,editable
{{#include ../../code/introduction/smart-pointers/using_make_unique.cc}}
```

Now your memory will be destroyed when it goes out of scope.
