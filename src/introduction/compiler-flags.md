# Compiler Flags

Compiler flags allow the compiler how strict we want it to be.

Some flags to use are:

`-std=c++20` -> This sets the version of C++ to C++20, the most modern version.

`-Wall` -> Sets lots of warnings on your compiler.

`-Wextra` -> Sets more warning flags not used by `-Wall`.

`-Wpedantic` -> Force strict ISO C++.

`-O0` -> no optimization. For debug builds, as this compiles quickly, but runs slowly.

`-O1` -> some optimization is enabled.

`-O2` -> more optimization is enabled.

`-O3` -> most optimization is enabled. This compiles the slowest but runs the fastest.
