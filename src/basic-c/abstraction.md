# Abstraction

Even though C is not an object-oriented language, it still allows for basic abstraction facilities with the `static` keyword.

`Static` forces a `.c` file to have internal linkage, which means that it cannot be linked to another `.c` file.

Let's see an example:

There is a main.c file which will run our code.
The library.c file contains the concrete implementation of the code.
The library.h file contains the exported interface to use.

```c,editable
// main.c
{{#include ../../code/scratch/c/abstraction/main.c}}
```

```c,editable
// library.c
{{#include ../../code/scratch/c/abstraction/library.c}}
```

```c,editable
// library.h
{{#include ../../code/scratch/c/abstraction/library.h}}
```

If you compile this setup:

```sh
gcc main.c library.c
```

You'll get a compile error. For me, this results in a linker error, where the object file generated cannot locate the `private` file, because it doesn't have external linkage, even though we defined it in the header file.

```sh
Undefined symbols for architecture x86_64:
  "_private", referenced from:
      _main in cch3qiYu.o
ld: symbol(s) not found for architecture x86_64
collect2: error: ld returned 1 exit status
make: *** [all] Error 1
```

Let's show something more involved: an example of abstraction by changing to a more practical example.

Let's say that we create a math.h header that contains the functions we want our users to use (add and sub).

```c,editable
// math.h
{{#include ../../code/scratch/c/abstraction/math.h}}
```

We need to implement the functions that our users will be using in our math.c file, so let's do that.

As well, we provide two different ways of doing addition and subtraction (using bitwise operators and using operators) and declare them as static (so they cannot be used outside of the file).

```c,editable
// math.c
{{#include ../../code/scratch/c/abstraction/math.c}}
```

Here we can try to use the static functions directly:

```c,editable
// main.c
{{#include ../../code/scratch/c/abstraction/math_main_using_static_function.c}}
```

Compile and run it, making sure to provide both the math.c and main.c files to the compiler:

```sh
${c_compiler} main.c math.c
```

You should get a compiler error calling the `_add` function directly, since it has internal linkage and is not visible to the main.c file.

```sh
Undefined symbols for architecture x86_64:
  "__add", referenced from:
      _main in ccXirzR1.o
ld: symbol(s) not found for architecture x86_64
collect2: error: ld returned 1 exit status
make: *** [all] Error 1
```

Let's use the exported `add` function instead:

```c,editable
// main.c
{{#include ../../code/scratch/c/abstraction/math_main.c}}
```

```sh
${c_compiler} main.c math.c
```

I get an output of 7, as expected.

```sh
7
```

## Changing Implementation

Let's say for some reason we want to switch from using the addition and subtraction operators to using the bitwise operators:

We can simply comment out our previous code and swap over to the new implementation. As long as the function gives the same output on all inputs, we should be good to go. Users don't have to change their code that uses our library at all, since we haven't changed the public interface.

```c,editable
// math.c
{{#include ../../code/scratch/c/abstraction/math_using_bitwise.c}}
```

```c,editable
// main.c
// Still Works!
{{#include ../../code/scratch/c/abstraction/math_main.c}}
```

Because of this reason, when writing library code, you should seek to make as much of your interface private as possible. Think of your header files as a contract that you need to fulfill with your users -- you can never strengthen or weaken the conditions of the contract without possibly breaking code that a user may use.

If we strengthen a condition (let's say our add and subtraction functions take a smaller set of input, like a short instead of an int), integers that overflow a short will return a different output, so our users will run into bugs.

```c,editable
// main.c
{{#include ../../code/scratch/c/abstraction/math_short.c}}
```

If we weaken a condition (let's say our function now accepts and returns long longs), sure we've allowed our users to provide us more inputs, but it's not out of the realm of possibility that they really wanted us to use a 4-byte int instead of an 8-byte long long and could suffer for performance reasons.

Every public interface should, to the best of its ability, use the same types and operate on the same inputs and outputs. Reducing the amount of public interfaces helps us do that.
