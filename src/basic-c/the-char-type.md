# The Char Type

As we started exploring the char type in the last chapter, let's continue on by explaining what it does for us.

We learned that the char type can hold numbers from -128 to 127, and the unsigned char type can hold numbers from 0 to 255. But char stands for character, so it's odd that you can store integers in it...

You can store characters in it as well. Here, we'll provide the format string of `%c` to `printf` to print out our string we provide as an ASCII character.

```c,editable
{{#include ../../code/basic-c/char_as_characters.c}}
```

That should print out the following when you compile and run it:

```sh
h
```

We can also ask the char for its numeric representation by printing it as a number, like we did in the previous chapter. We'll use the format string `%hhu` to turn our same character into a number.

```c,editable
{{#include ../../code/basic-c/char_as_number.c}}
```

That prints out:

```sh
104
```

Here's an ASCII table that displays all of the characters (courtesy of [Ascii Code](https://www.ascii-code.com/)).

<details>
  <summary>ASCII table</summary>

{{#include ../../code/basic-c/ascii-table.md}}

</details>

ASCII is a character encoding that allows the english alphabet (52 characters + extras) to be encoded into 7 bits of data (128 characters).

As you can see, lowercase `h` lines up with 104.

Let's see what happens when we add 1 to `h`.
What do you think should print?

```c,editable
{{#include ../../code/basic-c/h_plus_one.c}}
```

I get:

```sh
i
```

And that makes sense; lowercase i corresponds to `105` in ascii. When we add to a character, we're turning both sides into numbers, and then looking up what the value means in ASCII when we display it as a character.

Of course, we could also display it as a number.

```c,editable
{{#include ../../code/basic-c/h_plus_one_as_number.c}}
```

I get:

```sh
105
```

What about a number as a char?

```c,editable
{{#include ../../code/basic-c/char_as_zero.c}}
```

I get:

```sh
48
```

When a number is enclosed in single quotes, it is considered a `char` type, and so, we get back the equivalent ascii number as decimal, which is 48.

We can add to 0 with numbers to get different numbers:

```c,editable
{{#include ../../code/basic-c/add_zero_to_one_ascii.c}}
```

I get:

```sh
53
```

Finally, let's string together some chars to make a sentence.

```c,editable
{{#include ../../code/basic-c/hello_world_as_chars.c}}
```

I get:

```sh
hello
```

But this seems like a pain, doesn't it? Wouldn't it be nice to be able to declare more than one word at a time?

## Conclusion

We've learned that char types represent both a number type and a character type, but are held as numbers. As well, we found out that we can do arithmetic with the underlying numbers and turn them into chars as we wish.

## Exercises

- Change our program above to print out `hello world` instead of just hello, using characters.
  - Be careful, as variables cannot have the same name, so you'll have to name the second o and third l as something other than 'o' and 'l'.

## More Resources

[ASCII, wikipedia](https://en.wikipedia.org/wiki/ASCII)
