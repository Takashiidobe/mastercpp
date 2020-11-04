# Auto

The `auto` keyword allows for type inference. In general, this keyword tells the compiler to figure out the type it refers to.

This can come in handy when you have a long type declaration on both sides.

```cpp,editable
{{#include ../../code/introduction/auto/auto_map.cc}}
```

Auto also defaults to certain types if it can infer it:

For example:

```cpp,editable
{{#include ../../code/introduction/auto/double_and_int_inference.cc}}
```

Auto infers the type of numbers with a decimal point to be `double`, and integers to be `int`.

Perhaps surprisingly, auto infers string literals to be `const char[length + 1]`, instead of std::string.

```cpp,editable
{{#include ../../code/introduction/auto/string_literal_inference.cc}}
```

To make C++ infer a string, you can import an operator overload on `const char[]s` to make auto interpret them as a string by importing the `<string>` header, writing `using std::string_literals::operator""s`, and suffixing the string after auto with an s.

```cpp,editable
{{#include ../../code/introduction/auto/infer_auto_to_string.cc}}
```

Function type inference:

Auto can also be used to infer the return type of a function.

```cpp,editable
{{#include ../../code/introduction/auto/function_inference.cc}}
```

Since the function above concatenates and returns two std::strings, it must return a std::string, which auto infers for us.

Trailing return type syntax:

You can append the type of auto after the function.

```cpp,editable
{{#include ../../code/introduction/auto/trailing_return_type_syntax.cc}}
```

In this case, we don't gain anything outside of having our functions line up.

However, with the trailing return syntax, we can use a decltype of our templated arguments to return the proper type of an item, which would previously not be possible.

```cpp,editable
{{#include ../../code/introduction/auto/decltype_auto_return_type.cc}}
```
