# Static

The `static` keyword in C has two different meanings based on where you use it -- let's take a look at some examples.

First, when you use the static keyword inside of a function, it keeps its value between invocations.

```c,editable
{{#include ../../code/basic-c/static/static_in_function.c}}
```

If you compile and run this code you should get:

```sh
num is: 10, static_num is: 10
num is: 10, static_num is: 20
num is: 10, static_num is: 30
num is: 10, static_num is: 40
num is: 10, static_num is: 50
num is: 10, static_num is: 60
num is: 10, static_num is: 70
num is: 10, static_num is: 80
num is: 10, static_num is: 90
num is: 10, static_num is: 100
```

As you can see, we've managed to keep some state inside of the function: this is similar to a global variable, but encapsulated inside of the function.

Try to avoid using static variables inside functions when you can though -- your code will become harder to understand because static variables inside of a function make it harder to understand.

The other use of `static` is to make a variable or function usable only in the file it is defined in.

make a lib.c file that contains a static int, int, a static function that returns a string, and a function that returns a string:

```c,editable
//lib.c
{{#include ../../code/basic-c/static/project/lib.c}}
```

Declare them in our header file to include:

```c,editable
//lib.h
{{#include ../../code/basic-c/static/project/lib.h}}
```

Make a `main.c` file that uses `lib.h`

```c,editable
//main.c
{{#include ../../code/basic-c/static/project/main.c}}
```

Make a `Makefile` to compile the project.

```c,editable
//Makefile
{{#include ../../code/basic-c/static/project/Makefile}}
```

compile and run the project with `make`.

You should get something along this lines:

```sh
main.c:8:18: warning: format specifies type 'char *' but the argument has type 'const char *(*)()' [-Wformat]
  printf("%s\n", hello);
          ~~     ^~~~~
In file included from main.c:3:
./lib.h:7:20: warning: function 'static_hello' has internal linkage but is not defined [-Wundefined-internal]
static const char* static_hello();
                   ^
main.c:9:18: note: used here
  printf("%s\n", static_hello());
                 ^
2 warnings generated.
lib.c:1:12: warning: unused variable 'static_five' [-Wunused-variable]
static int static_five = 5;
           ^
lib.c:4:20: warning: unused function 'static_hello' [-Wunused-function]
static const char* static_hello() { return "Hello"; }
                   ^
2 warnings generated.
Undefined symbols for architecture x86_64:
  "_static_hello", referenced from:
      _main in main-4ca1ca.o
ld: symbol(s) not found for architecture x86_64
clang: error: linker command failed with exit code 1 (use -v to see invocation)
gmake: *** [Makefile:2: all] Error 1
```

The error is telling us that the linker cannot find` static_five` or `static_hello` during the linking process. Functions and variables in global scope that are declared `static` have internal linkage -- they can not be used to other files.

## More Resources

[What does "static" mean in C?](https://stackoverflow.com/questions/572547/what-does-static-mean-in-c)
