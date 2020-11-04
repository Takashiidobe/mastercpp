# Structured Bindings

The venerable C style for loop gives one a lot of control in how to loop. You can loop forwards, backwards, increment your counter variable any amount, decrement it any amount, or do nothing. But most of the time we don't need that control; we just want to be able to do something for every item in a collection.

```cpp,editable
{{#include ../../code/introduction/structured-bindings/c_style_for_loop.cc}}
```

And this works fine. But we might mistype something.

```cpp,editable
{{#include ../../code/introduction/structured-bindings/c_style_for_loop_error.cc}}
```

Oops. Out of bounds access. We're asking the vector for its fifth element when it only has four. What we really mean to say is "print out the value for every item in the array."

Enter the `For Each` loop.

Now I will never have an out of bounds access!

```cpp,editable
{{#include ../../code/introduction/structured-bindings/for_each_loop.cc}}
```

But what if I want the index, which comes in handy sometimes? I can initialize i to be 0, and increment it at the end of the block. Now i is captured inside of the for loop, and doesn't leak outside.

```cpp,editable
{{#include ../../code/introduction/structured-bindings/for_each_loop_with_index.cc}}
```
