#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omartyno <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/16 15:53:24 by omartyno          #+#    #+#              #
#    Updated: 2017/04/02 13:10:22 by omartyno         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME=../asm
VPATH=src:inc
HEAD=asmblr.h
LIBFT=libft.a
LIBFTPATH=./libft
SRC=main.c get_next_line.c err_handler.c get_describe.c comments_skip.c \
white_char.c hash_table.c cor_name.c make_nc.c ophash.c op.c start_write.c\
write_int_in.c get_cmd.c is_label_char.c make_command.c read_argument.c\
properties.c extract_from_quotes.c
OBJ=$(SRC:.c=.o)
FLAGS=-Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(OBJ) $(LIBFT)
	gcc $(FLAGS) -o $(NAME) $^

$(LIBFT): 
	make -C $(LIBFTPATH); make clean -C $(LIBFTPATH);
	mv $(LIBFTPATH)/$(LIBFT) ./;

.c.o: $(SRC)
	gcc -c $(FLAGS) $<

$(OBJ): $(HEAD)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f $(LIBFT)

re: fclean all