# Function Pointers

So far we've learned how to declare our own types by using a `struct`. But you'll notice we can't define any kind of functions inside of our structs.

That changes with the addition of `function pointers`.

With function pointers, we can put functions inside of our structs, and with `encapsulation`, we can make it so those functions aren't callable outside of the struct, so each struct will carry all of its dependencies.

Let's take a look.

First, let's define a struct, call it person, and make it contain a `char*` for name and `size_t` for age.

that would look something like this:

```c,editable
{{#include ../../code/scratch/c/function-pointers/person/person_struct.c}}
```

This is great, but let's try to add some helper functions. Normally how we would do that would be to create a function that would accept a struct Person and some optional parameters and manipulate the struct that way.

But all of those loose functions would clutter up the global namespace if we were to do it as we suggested originally.

We have no way out except for the fact that pointers are flexible enough to call a function inside a struct.

The syntax is:

`$return_type (*$function_name)($argument_type $argument_name);`

Here's an example using our person struct.

```c,editable
{{#include ../../code/scratch/c/function-pointers/person/person_struct_pointer.c}}
```

We declare a member of the struct that will take a Person struct and forward it over to a different function that we specify that accepts a Person struct.

To make that function invisible to other translation units, we have to create a static function that returns a size_t and assign it to Person.

```c,editable
{{#include ../../code/scratch/c/function-pointers/person/person_struct_get_age.c}}
```

We can do that here: we make a function called `get_age` that does what we need to do.

But we need a way to initialize the function.

Since doing this setup manually is a bit messy, let's wrap our initialization in a function.

We want to do the following:

1. allocate a new `struct Person*` on the heap.
2. connect our static get_age function to the get_age member in the struct.
3. return the `struct Person*`.

```c,editable
{{#include ../../code/scratch/c/function-pointers/person/person_struct_init.c}}
```

Perfect. Now we have a way to create our Person, and get its age. You can do that like this:

```c,editable
{{#include ../../code/scratch/c/function-pointers/person/person_get_age_main.c}}
```

Of course, in this case we'll get an assert trap because we've never set the age of the person.

Let's write a function pointer that sets the age of the person before getting it.

```c,editable
{{#include ../../code/scratch/c/function-pointers/person/person_getter_setter_age.c}}
```

Then let's use that function and see what we get.

```c,editable
{{#include ../../code/scratch/c/function-pointers/person/person_getter_setter_age_main.c}}
```

If you compile and run this, you should finally get the output of 20, since we set the age to 20 before reading from it.

## Conclusion

We've learned that the we can get around the restriction of not having functions in structs by using function pointers.

## Exercises

Write a getter and setter for the Person struct, and write a custom free function that will free the struct when it is no longer needed.
