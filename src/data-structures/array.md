# Array

Array:

The array is much like a C-style array, but it doesn't decay to a pointer, but with a similar API to the rest of the STL containers.

```cpp,editable
{{#include ../../code/scratch/cc/stl/containers/sequence/array/array.cc}}
```

Arrays are a fixed size, so there are no operators which can grow or shrink an array.

You have a few methods on the class itself, as well as some constructors that are useful.

At:

`At` returns or sets the item in the array with bounds checking (if you ask for an index which is not in the array, you get a std::out_of_range exception).

```cpp,editable
{{#include ../../code/scratch/cc/stl/containers/sequence/array/array_at_operator.cc}}
```

Operator[]:

`operator[]` is like `at`, but without bounds checking. If you ask for an index which is not in the array, undefined behavior occurs.

```cpp,editable
{{#include ../../code/scratch/cc/stl/containers/sequence/array/array_square_bracket_operator.cc}}
```
