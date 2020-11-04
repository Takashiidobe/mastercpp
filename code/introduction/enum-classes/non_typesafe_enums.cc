#include <iostream>

int main() {
  enum Color { Blue, Red, Green };
  enum Mood { Happy, Angry, Blue };

  Color color = Blue;
  Mood mood = Happy;

  if (color == mood)
    std::cout << "My color is equal to my mood.\n";  // this prints, because
                                                     // color = 0 and mood = 0.
}
