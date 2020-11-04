# Ranges

C++20 adds a new feature called ranges.

In old C++, to sort a collection, you might try:

```cpp,editable
{{#include ../../code/introduction/ranges/pre_ranges_sort.cc:}}
```

Now you don't have to provide the begin and the end, and can sort using the ranges version of sort, which has a begin and end.

```cpp,editable
{{#include ../../code/introduction/ranges/ranges_sort.cc:}}
```
