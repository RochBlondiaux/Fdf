<h1 align="center">
	 FDF
</h1>

<p align="center">
	<b><i>Development repo for 42cursus' fdf project</i></b><br>
	For further information about 42cursus and its projects, please refer to <a href="https://github.com/rochblondiaux/42cursus"><b>42cursus repo</b></a>.
</p>

<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/rochblondiaux/fdf?color=blueviolet" />
	<img alt="Number of lines of code" src="https://img.shields.io/tokei/lines/github/rochblondiaux/fdf?color=blueviolet" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/rochblondiaux/fdf?color=blue" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/rochblondiaux/fdf?color=blue" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/rochblondiaux/fdf?color=brightgreen" />
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

> _The aim of this project is to make you code a function that returns a line ending with a newline, read from a file._

For detailed information, refer to the [**subject of this project**](https://github.com/RochBlondiaux/fdf/blob/main/fr.subject.pdf).

	🚀 TLDR: This project consists of graphically creating a schematic representation of a relief terrain.

## 📑 Index

`@root`

* [**📁 includes:**](includes/) contains all prototypes and libraries includes.
* [**📁 srcs:**](srcs/) contains all project sources files.
  * [**📁 gnl:**](srcs/gnl/) contains the get_next_line project sources.
  * [**📁 libft:**](srcs/libft/) contains the libft project sources.
  * [**📁 mlx:**](srcs/mlx/) contains the [minilibx](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html) sources.
  * [**📁 parsing:**](srcs/parsing/) contains all parsing related files.
  * [**📁 hooks:**](srcs/hooks/) contains all keys hooks files.
  * [**📁 graphics:**](srcs/hooks/) contains all graphics related files.
  * [**📁 utils:**](srcs/utils/) contains all utilities files.

`@/srcs/main.c`
* `main` - Start the program and setup the window.
* `setup_image` - setup image in window.
* `render` - render image to window.

`@/srcs/graphics/`
* `ft_render_pixel` - Draw a pixel on the screen.
* `ft_render_line` - Draw a line between two points.
* `ft_render_rectangle` - Draw a rectangle between two points.

`@/srcs/hooks/`
* `ft_exit_hook` - Close program on escape key press.

`@/srcs/parsing/`
* `ft_check_point` -  Checks if a point is valid.
* `ft_load_map` - Load points from provided file. 
* `ft_parse_file` - Parse points from provided file.
* `ft_parse_line` - Parse points from a single line.
* `ft_join_points` - Join points lists together.

`@/srcs/utils/`
* `rgb_to_int` - Convert RGB color to integer.
* `ft_create_point` - Create a point structure from its x, y, z.
* `ft_points_size` - Get points list size.
* `ft_doublelenght` - Get bi-dimensional list length.
* `ft_create_position` - Create position structure from its x & y.

`@/srcs/gnl/`
* `ft_read`	- read & wrap a buffer from a file descriptor.
* `ft_read_next`	- concatenate last red buffer and latest one.
* `ft_find_nl`	- cut line at the right length.
* `get_next_line`	- main function.
* `ft_strlen`		- find length of string.
* `ft_strchr`		- find first instance of character.
* `ft_strlcpy`		- copy a string in a new address space.
* `ft_substr`		- cut a string from an index to another.
* `ft_strjoin`		- concatenate two strings.

`@/srcs/libft/`

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

The function is written in C language and thus needs the **`gcc` compiler** and some standard **C libraries** to run.

### Instructions

_Coming soon_

## 📋 Testing

_Coming soon_