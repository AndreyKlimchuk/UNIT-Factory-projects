#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/15 17:38:02 by aklimchu          #+#    #+#              #
#    Updated: 2017/02/19 14:54:59 by aklimchu         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = filler
LIBNAME = libft.a
PNAME = painter
SRC = filler.c input_handler.c sup_func.c solver.c
PSRC = painter.c
OBJ = $(subst .c,.o,$(SRC))
POBJ = $(subst .c,.o,$(PSRC))
HEADER = filler.h
FLS = -Wall -Wextra -Werror
VPATH = includes:libft:srcs:paint

all: $(NAME)

$(NAME): $(OBJ) $(POBJ) $(LIBNAME) $(PNAME)
	gcc $(FLS) $(OBJ) -o $(NAME) libft/$(LIBNAME)

$(PNAME):
	gcc $(FLS) $(POBJ) -o $(PNAME) libft/$(LIBNAME)

$(LIBNAME):
	make -c ./libft/

%.o: %.c $(HEADER)
	gcc $(FLS) -c -o $@ $< -I ./includes

clean:
	/bin/rm -f $(OBJ) $(POBJ) *~

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all