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
    <span> . </span>
    <a href="#-screenshots">Screenshots</a>
</h3>

---

## 🗣️ About

> _The aim of this project is to make you code a function that returns a line ending with a newline, read from a file._

For detailed information, refer to the [**subject of this project**](https://github.com/RochBlondiaux/fdf/blob/main/fr.subject.pdf).

	🚀 TLDR: This project consists of graphically creating a schematic representation of a relief terrain.

## 📑 Index

`@root`

* [**📁 includes:**](includes/) contains all prototypes and libraries includes.
* [**📁 gnl:**](get_next_line/) contains the get_next_line project sources.
* [**📁 mlx:**](mlx/) contains the [minilibx](https://harm-smits.github.io/42docs/libs/minilibx/getting_started.html) sources.
* [**📁 libft:**](libft/) contains the libft project sources.
* [**📁 glib:**](glib/) contains the glib project sources.
* [**📁 srcs:**](srcs/) contains all project sources files.
  * [**📁 controls:**](srcs/controls/) contains all controls related files.
  * [**📁 parsing:**](srcs/parsing/) contains all parsing related files.
  * [**📁 graphics:**](srcs/hooks/) contains all graphics related files.
  * [**📁 utils:**](srcs/utils/) contains all utilities files.

`@/srcs/main.c`
* `main` - Starts the program.
* `init_camera` - Initializes virtual camera.
* `init` - Initializes camera & set default projection.
* `init_window` - Initializes window & image via the glib.

`@/srcs/graphics/`
* `render` - Renders backgrounds and lines to window.
* `clear_image` - Draws the background.
* `draw_lines` - Draws lines from vector list.
* `project` - Projects image using isometric or parallel function, rotate & fit camera.

`@/srcs/controls/`
* `close_fdf` - Closes program on escape key press.
* `change_projection` - Changes projection between parrallel & isometric.
* `dispatch_keys` - Calls accurate functions when a key is pressed.
* `register_controls` - Registers keys events.
* `movement_control` - Manage camera movements controls.
* `rotation_control` - Manage camera rotation controls.
* `zoom` - Manage camera zoom controls.

`@/srcs/parsing/`
* `parse_map` - Loads points from provided file. 
* `parse_file` - Parses points from provided file.
* `parse_line` - Parses points from a single line.
* `create_map` - Creates map in heap memory stack.
* `v3f_validate` - Validates vectors 3f.
* `free_map` - Free the map and all its components in memory to avoid leaks.

`@/srcs/utils/`
* `create_point` - Creates a point.
* `convert_vectors` - Converts vectors 3f to points list.
* `get_point_color` - Gets point color.
* `isdigit_base` - Checks if a base is digit.
* `has_prefix` - Checks if base prefix is present.
* `atoi_base` - Parses hexadecimals from string.
* `get_index` - Gets point index.
* `new_3d_point` - Creates new vector 3f from 2D point.
* `get_default_color` - Gets default color of a point from its altitude (z).
* `v3f_length` - Gets length of a vector3f array.
* `double_length` - Gets length of a pointer on pointer on char.
* `free_parts` - Frees pointer on pointer on char.
* `allocate_v3f` - Creates a new vector3f from parsing.
* `join_v3f` - Concatenates two arrays of vector 3f.
* `is_empty` - Checks if a string is empty.
* `is_fdf_map` - Checks if filename has extension ".fdf".
* `create_vector3f` - Create new vector 3f from its coordinates.

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

#### 1. Installation
In order to install the fdf, you need to clone it:
```bash
git clone https://github.com/RochBlondiaux/Fdf.git && cd Fdf
```
Then, compile it with make:
```bash
make
```

#### 2. Usage
It's really simple, you just have to execute this command:
```bash
./fdf my_map.fdf
```
The program only accept `.fdf` files, you can use maps from the `maps/` folder,
create your owns or even generate them with [42MapGenerator](https://github.com/jgigault/42MapGenerator).

## 📷 Screenshots

<img alt="T1 Map" src="t1.gif" width="250px"/>
<img alt="42 Map" src="42.gif" width="300px"/>
<img alt="T1 Map" src="https://i.gyazo.com/8e260e1ae2c4effba56b3c33ddb36e28.gif"/>
<img alt="Earth Map" src="https://i.gyazo.com/558fe4399dcc4a2c587e60b1b992dc84.png"/>