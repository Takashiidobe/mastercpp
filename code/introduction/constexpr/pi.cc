const double PI = 22 / 7;  // this works

constexpr auto calculate_pi() { return 22.0 / 7; }

constexpr double PI = calculate_pi();
