# Enum Classes

C++ supports C style enums, which have multiple pitfalls in their use -- we'll go over some of these and a C++ feature meant to replace them, Enum classes.

First of all, C style nums pollute the local namespace. So you can't create two separate enums with the same member.

```cpp,editable
{{#include ../../code/introduction/enum-classes/colors.cc}}
```

No variables with the name of an enum member can be used either.

```cpp,editable
{{#include ../../code/introduction/enum-classes/variables_in_class.cc}}
```

Enums are also not typesafe:

```cpp,editable
{{#include ../../code/introduction/enum-classes/non_typesafe_enums.cc}}
```

As well, C style enums are cast into a 8 bit int when compared, (a value from 0-255), which is somewhat limiting. What if we wanted a char? or a wider 16 bit int?

Enter the enum class.

```cpp,editable
{{#include ../../code/introduction/enum-classes/enum_class.cc}}
```

As well, we can change the type of enum to that of an integral type, and set the value of the enums arbitrarily.

```cpp,editable
{{#include ../../code/introduction/enum-classes/enum_class_char.cc}}
```
