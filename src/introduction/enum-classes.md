# Enum Classes

C++ supports C style enums, which have multiple pitfalls in their use -- we'll go over some of these and a C++ feature meant to replace them, Enum classes.

First of all, C style nums pollute the local namespace. So you can't create two separate enums with the same member.

```cpp
enum Color { Blue, Red, Green };
enum Mood { Happy, Angry, Blue }; // compilation error, Blue conflicts with a previous declaration in Color
```

No variables with the name of an enum member can be used either.

```cpp
enum Color { Blue, Red, Green };
class Green { Color color = Blue; }; // compilation error, Green conflicts with a previous declaration in Color.
```

Enums are also not typesafe:

```cpp
#include <fmt/core.h>

int main() {
  enum Color { Blue, Red, Green };
  enum Mood { Happy, Angry, Blue };

  Color color = Blue;
  Mood mood = Happy;

  if (color == mood)
    fmt::print("My color is equal to my mood."); // this prints, because color = 0 and mood = 0.
}
```

As well, C style enums are cast into a 8 bit int when compared, (a value from 0-255), which is somewhat limiting. What if we wanted a char? or a wider 16 bit int?

Enter the enum class.

```cpp
#include <fmt/core.h>

int main() {
  enum class Color { Blue, Red, Green };
  enum class Mood { Happy, Angry, Blue };

  Color color = Color::Blue;
  Mood mood = Mood::Happy; // scoped enums now.

  auto Blue = "This works now!"; // Blue is no longer in this namespace.

  if (color == mood)
    fmt::print("My color is equal to my mood."); // this throws a compile time error, because the type of Color does not match type of Mood.
}
```

As well, we can change the type of enum to that of an integral type, and set the value of the enums arbitrarily.

```cpp
#include <fmt/core.h>

int main() {
  enum class Color: char { Blue = 'b', Red = 'r', Green = 'g' };
  fmt::print("{}", Color::Blue); // prints 'b' for Blue.
}
```
