#include <iostream>

int main() {
  enum class Color { Blue, Red, Green };
  enum class Mood { Happy, Angry, Blue };

  Color color = Color::Blue;
  Mood mood = Mood::Happy;  // scoped enums now.

  auto Blue = "This works now!";  // Blue is no longer in this namespace.

  if (color == mood)
    std::cout << "My color is equal to my mood."
              << '\n';  // this throws a compile time error,
                        // because the type of Color does not
                        // match type of Mood.
}
