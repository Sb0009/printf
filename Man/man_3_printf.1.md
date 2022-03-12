---
title: _PRINTF
section: 1
header: User Manual
footer: printf 1.0.0
date: The 11th of March, 2022
authors: Written by Nicolas Boute and Siham Badyine
---

# NAME
_printf - this function is used for printing data input.

# SYNOPSIS
**man printf** [*OPTION*]...

# DESCRIPTION
**_printf** produces output according to a format
 

# OPTIONS
**-h** 
: display help message

**-n** 
: name of the person to say hello to


# EXAMPLES

** To print "Hello doc !" use:

#include "main.h"

_printf("%s", "Hello doc !");

: To print "My favorite number is, 42" use:

#include "main.h"

_printf("%s, %d", "My favorite number is", 42);**



# BUGS
Submit bug reports online at: <4330@holbertonschool.com>

# SEE ALSO
. Full documentation and sources at: <>



# PROTOTYPE H.FILE

** int _printf(const char *format, ...);**

** Print ARGUMENT(s) according to FORMAT as a string before the "%"

. Return the number of characters printed (excluded the null byte)

# FORMAT: string of characters.
. The format string is composed of zero or more directives. See man 3 printf.

. Converter

 .[c] Character.

 .[d] or [i]: decimal integer.
 
. [e] Scientific notation (mantissa/exponent) using e character.

. [E] Scientific notation (mantissa/exponent) using E character.

. [f] Decimal floating point.

. [g] Uses the shorter of %e or %f.

. [G] Uses the shorter of %E or %f.

. [o] Octal.

. [s] String of character.

. [u] Unsigned decimal integer.

. [x] Unsigned hexadecimal integer.

. [x] Unsigned hexadecimal integer (capital letters).

. [p] Pointer .

. [n] Nothing printed.

. [%] Character.

. [none] print normally (right justify, space fill)

. [-] left justify

. [0] leading zero fill

. [+] print plus on numbers.

# AUTHORS: Written by Nicolas Boute and Siham Badyine for Holberton School

