# Structs

Structs allow you to define your own custom types in C. If you want to create your own type that is a collection of C's data types, you can do that with a struct. (struct is short for structure).

You can declare a struct like this:

```c,editable
{{#include ../../code/basic-c/structs/struct.c3:6}}
```

You can then initialize it and assign to its members manually like so:

```c,editable
{{#include ../../code/basic-c/structs/struct.c8:10}}
```

You can also just initialize and instantiate inline in three different ways:

The 3rd way (p3) is a GNU only extension (for gcc), which was deprecated after C99 came out with the equals syntax (the one used for p2). The way in use for p2 should be favored, since you can write them in any order and you are explicit about which member you're assigning to.

```c,editable
{{#include ../../code/basic-c/structs/initialize_inline.c9:11}}
```

Structs are useful for aggregating data. Instead of having to keep track of a few variables for every group of variables we want to treat as a group, we can treat them as one struct.

Structs can also be arbitrarily nested, which is important -- structs can contain other structs.Infinitely.

Let's make a 3d point that's composed of structs of X, Y, Z.

This is a bit of a contrived example because we could just make x, y, and z members of the Point struct.

```c,editable
{{#include ../../code/basic-c/structs/structs_in_structs.c}}
```

## Anonymous Structs

If you are on C11, you can initialize anonymous structs, where you can directly access their members without accessing them by name.

This is good to remove a bit of boilerplate: look at how simple our struct instantiation is now.

```c,editable
{{#include ../../code/basic-c/structs/anonymous_point_struct.c}}
```
