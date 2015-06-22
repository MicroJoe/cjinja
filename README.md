# cjinja, a kind of jinja, in C

This is a small prototype of rewritting some of the basic Python Jinja2 library
template parsing functions into bare C.

## Why this?

Jinja2 templates have a very readable syntax, but sometimes invoking the whole
Python environment to do very simple template parsing/rendering may look a bit
of a overhead.

Instead we can try to write down a small C parser/renderer which will only
handle the very low basics of this template language. ATM this program/library
will aim to do fields substitution only, because it seems simple.

## Compile

You will not need any fancy libraries to compile this. A C89 compliant C
compiler and a decent UNIX stdlib will be enough to compile this using the
provided Makefile.

## Example

You can run the program on the provided example text file to see that the
program correctly matches the tags.

	./cjinja < example.txt

## Copyright

This program is brought to you under WTFPL. For further informations please
read the provided COPYING file.
