# UNIT-Factory-projects
Repository for my UNIT Factory projects

LIBFT

The goal of this project is to create own library composed of recoded functions from 
basic C libraries and extend it by your own useful functions in future.

Usage: Compile your project with this library and use functions from it whenever it is need.

FILLIT

The goal of this project is to arrange the Tetriminos (4-blocks geometric figure from tetris) themselves to make the
smallest possible square, but in some cases, this square may have holes when some given
pieces won’t fit perfectly with others. Among the different solutions
possible to make the smallest square, only the solution where Tetriminos is placed on
their most upper-left position, is acceptable.

Usage: Run program and pass as argument file with valid tetreminos. For example ./fillit test

GET NEXT LINE

The goal of this project is to write a function that returns a line read from a file descriptor. “line” is a succession of characters that end with ’\n’ (ascii code 0x0a) or with End Of File (EOF). The return value can be 1, 0 or -1 depending on whether a line has been read, when the reading has been completed, or if an error has happened respectively. Calling this function in a loop will then allow you to read the text available on a file descriptor one line at a time until the end of the text, no matter the size of either the text or one of its lines.

Usage: use this function whenever you need to read from file or input stream (just pass different file descriptors). You can use this function in a loop until it return 0, it will means that file have been read completely.
