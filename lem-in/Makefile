#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/09 16:00:31 by aklimchu          #+#    #+#              #
#    Updated: 2017/02/11 16:12:34 by aklimchu         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = lem-in
LIBNAME = libft.a
SRC = input_handler.c farm_builder.c lem_in.c sup_func.c solver.c \
solver_helper.c
OBJ = $(subst .c,.o,$(SRC))
HEADERS = lem_in.h libft.h
FLS = -Wall -Wextra -Werror
VPATH = includes:libft:srcs

.PHONY: all clean fclean re

all: $(NAME)

$(NAME) : $(OBJ) $(LIBNAME)
	gcc $(FLS) $(OBJ) -o $(NAME) libft/$(LIBNAME)

$(LIBNAME) :
	make -c ./libft/

%.o: %.c $(HEADERS)
	gcc $(FLS) -c -o $@ $< -I ./includes

clean:
	/bin/rm -f $(OBJ) *~

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all