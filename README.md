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

GET_NEXT_LINE

The goal of this project is to write a function that returns a line read from a file descriptor. “line” is a succession of characters that end with ’\n’ (ascii code 0x0a) or with End Of File (EOF). The return value can be 1, 0 or -1 depending on whether a line has been read, when the reading has been completed, or if an error has happened respectively. Calling this function in a loop will then allow you to read the text available on a file descriptor one line at a time until the end of the text, no matter the size of either the text or one of its lines.

Usage: Use this function whenever you need to read from file or input stream (just pass different file descriptors). You can use this function in a loop until it return 0, it will means that file have been read completely.

FT_PRINTF

The goal of this project is to recode the libc’s printf function.

Usage: Compile your project with libftprintf.a library and use ft_printf function instead standart printf.

PUSH_SWAP

The goal of this project is to write 2 programs in C:

• The first, named checker which takes integer arguments and reads instructions on the standard output. Once read, checker executes them and displays OK if integers are sorted. Otherwise, it will display KO.

• The second one called push_swap which calculates and displays on the standard output the smallest progam using Push_swap instruction language that sorts integer arguments received.
You have at your disposal a set of int values, 2 stacks and a set of instructions to manipulate both stacks.


Instructions list

sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there
is only one or no elements).

sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there
is only one or no elements).

ss : sa and sb at the same time.

pa : push a - take the first element at the top of b and put it at the top of a. Do
nothing if b is empty.

pb : push b - take the first element at the top of a and put it at the top of b. Do
nothing if a is empty.

ra : rotate a - shift up all elements of stack a by 1. The first element becomes
the last one.

rb : rotate b - shift up all elements of stack b by 1. The first element becomes
the last one.

rr : ra and rb at the same time.

rra : reverse rotate a - shift down all elements of stack a by 1. The flast element
becomes the first one.

rrb : reverse rotate b - shift down all elements of stack b by 1. The flast element
becomes the first one.

rrr : rra and rrb at the same time.


Usage: You can use programs in bash as follow 

ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG

or instead writing arguments manually use random number generator where as follow

ARG=$(./generator 12 0 100);./push_swap $ARG | ./checker $ARG

Next flags for checker program available:

-v - turns on the vizualizator

-n - at the end shows number of operation

-c - makes output colored

FILLER

The goal of this project is to create your player to fight other players on the world famous (or infamous) Filler board. The concept is simple: two players gain points by placing on a board, one after the other, the game piece obtained by the game master (in the form of an executable Ruby program). The game ends when the game piece cannot be placed anymore. 
In this game, two players fight each other. They play one after the other.
• The goal is to collect as many points as possible by placing the highest number of
pieces on the the game board.
• The board is defined by X columns and N lines, it will then become X*N cells.
• At the beginning of each turn, you will receive your game piece. 
• A game piece is defined by X columns and N lines, so it will be X*N cells. Inside
each game piece, will be included a shape of one or many cells. 
• To be able to place a piece on the board, it is mandatory that one, and only one
cell of the shape (in your piece) covers the cell of a shape placed previously (your
territory). 
• The shape must not exceed the dimensions of the board. 
• When the game starts, the board already contains one shape. 
• The game stops at the first error: either when a game piece cannot be placed
anymore or it has been wrongly placed. 

Usage: Run program from folder resors as follow:
./filler_vm -p1 ../filler -p2 ./players/[player name] -f ./maps/map[map_number] | ../painter
Flag -p allows to define player number. Player 2 represented by X and x characters and player 1 by O and o characters.

