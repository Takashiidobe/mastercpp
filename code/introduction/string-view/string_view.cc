#include <string>
#include <string_view>

auto str = std::string("Hello World");

auto sub_string = str.substr(0, 5);  // Linear Time copy.

std::string_view sv = str.substr(0, 5);  // Constant Time non-owning reference.
