<h1 align="center">
	 libft
</h1>

<p align="center">
	<b><i>Development repo for 42cursus' get_next_line project</i></b><br>
	For further information about 42cursus and its projects, please refer to <a href="https://github.com/rochblondiaux/42cursus"><b>42cursus repo</b></a>.
</p>

<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/rochblondiaux/libft?color=blueviolet" />
	<img alt="Number of lines of code" src="https://img.shields.io/tokei/lines/github/rochblondiaux/libft?color=blueviolet" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/rochblondiaux/libft?color=blue" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/rochblondiaux/libft?color=blue" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/rochblondiaux/libft?color=brightgreen" />
</p>

<h3 align="center">
	<a href="#%EF%B8%8F-about">About</a>
	<span> · </span>
	<a href="#-index">Index</a>
	<span> · </span>
	<a href="#%EF%B8%8F-usage">Usage</a>
	<span> · </span>
	<a href="#-testing">Testing</a>
</h3>

---

## 🗣️ About

> The aim of this project is to code a C library regrouping usual functions that you'll be allowed to use in all your other projects.

For detailed information, refer to the [**subject of this project**](https://github.com/RochBlondiaux/libft/blob/main/fr.subject.pdf).

	🚀 TLDR: this project consists of coding basic C functions (see below), which are then compiled into a library for use in other projects of the cursus.

## 📑 Index

`@root`

_Note: files contain both mandatory and all bonus requirements._

Basic Libc functions

* `ft_strlcpy`	- copy string to another location
* `ft_strlcat`	- concatenate strings
* `ft_strdup`	- save a copy of a string (with malloc)
* `ft_strjoin`	- join two strings (with malloc)
* `ft_substr`	- extract a substring (with malloc)
* `ft_atoi`	    - convert a string to an integer
* `ft_isascii`	- check if a character is in the ascii table
* `ft_isprint`  - check if a character is printable
* `ft_isdigit`	    - check if a character is a digit
* `ft_isupper`	    - check if a character is uppercase
* `ft_islower`	    - check if a character is lowercase
* `ft_memset`	    - fill memory with a constant byte
* `ft_memmove`	    - copy memory area
* `ft_strlcpy`	    - size-bounded string copying
* `ft_strlcat`	    - size-bounded string concatenation
* `ft_strchr`	    - locate first character instance in string
* `ft_strrchr`	    - locate last character instance in string
* `ft_strncmp`	    - compare two strings within given size
* `ft_memchr`	    - scan memory for a character
* `ft_memcmp`	    - compare memory areas
* `ft_strnstr`	    - locate a substring in a string
* `ft_calloc`	    - allocates memory for an array of a given length
* `ft_strdup`	    - duplicate a string

Additional functions

* `ft_substr`	- get a sub string from the original string
* `ft_strjoin`	- concatenate two strings
* `ft_strtrim`	- remove targeted characters
* `ft_split`	- split string into a 2d array
* `ft_itoa`	- convert numbers to string
* `ft_strmapi`	- apply a function on each character of a string
* `ft_striteri`	- execute a function on each character of a string
* `ft_putchar_fd`	- write a character
* `ft_putstr_fd`	- write a string
* `ft_putnbr_fd`	- write numbers
* `ft_putendl_fd`	- add a new line at the end of a file

Bonus functions
* `ft_lstnew`	- create a new linked list element
* `ft_lstadd_front`	- add an element to the front of a linked list
* `ft_lstsize`	- get the size of a linked list
* `ft_lstlast`	- get the last element of a linked list
* `ft_lstadd_back`	- add an element to the end of a linked list
* `ft_lstdelone`	- delete an element from a linked list
* `ft_lstclear`	- clear a linked list
* `ft_lstiter`	- apply a function to each element of a linked list
* `ft_lstmap`	- apply a function to each element of a linked list & create a new list

## 🛠️ Usage

### Requirements

The library is written in C language and thus needs the **`gcc` compiler** and some standard **C libraries** to run.

### Instructions

**1. Compiling the library**

To compile the library, run:

```shell
$ cd path/to/ft_printf && make
```

**2. Using it in your code**

To use the library functions in your code, simply include its header:

```C
#include "ft_printf.h"
```

and, when compiling your code, add the required flags:

```shell
-lftprintf -L path/to/libftprintf.a -I path/to/ft_printf.h
```

## 📋 Testing

* [alelievr/libft-unit-test](https://github.com/alelievr/libft-unit-test)
* [Tripouille/libftTester](https://github.com/Tripouille/libftTester)
* [ska42/libft-war-machine](https://github.com/ska42/libft-war-machine)