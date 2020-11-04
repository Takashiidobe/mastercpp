# Strings of Characters

We saw in the last section how we could use characters, but it's a bit cumbersome to type out a bunch of characters and then use them.

What we really want are a collection of strings.

If you look at the previous sentence, it really is just a collection of chars. ASCII allows us to express lowercase, uppercase, spaces, and punctuation.

Now all we need is a way to make a collection.
The collection type is called an `array`, and it holds values in a linear form, one by one, in order.

You can declare a `String`, which is an `array` of characters in the following ways.

We'll use the `%s` format string to print out the string.

```c,editable
{{#include ../../code/basic-c/string_hello.c}}
```

```c,editable
{{#include ../../code/basic-c/string_hello_as_arr.c}}
```

In general, the first one is a little less tedious to type out, so we will stick to that.

Great. We've managed to create a string that is an array. But let's access the string and change one of its values, shall we?

We called our variable hello. In arrays, we count from 0, so let's change the first (or zeroth) letter to 'a', by acccessing the location using square brackets like so.

```c,editable
{{#include ../../code/basic-c/string_hello_to_a.c}}
```

That prints out:

```sh
aello
```

We can set the letter using the equals sign, or we can just access it plainly and save the character into a variable by not using the equals sign.

So we can read a value however we like.

```c,editable
{{#include ../../code/basic-c/string_access.c}}
```

That prints out:

```sh
h
```

There is another way to intialize a char array that is similar.

Here, instead of putting brackets and the length, we put an `*`, asterisk character.

```c,editable
{{#include ../../code/basic-c/char_star_hello.c}}
```

That prints out:

```sh
hello
```

Great! Hey and we didn't have to provide the length, so this is even better.

To print out the first character of the string works fine here:

```c,editable
{{#include ../../code/basic-c/char_star_hello_read.c}}
```

That prints out:

```sh
h
```

But when we try to write to it:

```c,editable
{{#include ../../code/basic-c/char_star_hello_write.c}}
```

That prints out nothing:

```sh

```

Hmm. This is our first example of something called `Undefined Behavior`, and is one of the reasons that C and C++ are difficult languages to understand. In this case, char\* is located in read-only memory. When we declare a char[] (char with brackets), the string is located in read-only memory, but a copy of it is allocated in the program. Thus, when we refer to `char[]`, we can change it as we wish.

However, for the char _ version, our string is located in read-only memory. When we try to change the first letter of our `char _`version, it fails to do so, and results in`Undefined Behavior`, where the behavior of the program is not guaranteed.

If you would like to change the contents of a string, remember to use `char[]`. If you're fine without changing the contents of a string, feel free to use `char *`.

There are a few more differences we'll cover later, but that's the gist of it.

## Conclusion

We found that there are a few ways to allocate collections of characters, and string them together, as well as some of the pitfalls of strings in C.

## Exercises

- Write a string of "Hello World" and change the letters so it becomes "Yello World", and print it to the console.

## More Resources

- [What is the difference between char array and char pointer in C?](https://stackoverflow.com/a/10187933/8721286)
