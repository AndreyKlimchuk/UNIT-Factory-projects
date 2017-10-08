#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/02 11:23:48 by aklimchu          #+#    #+#              #
#    Updated: 2017/04/02 11:45:38 by aklimchu         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = ../corewar
LIBNAME = libft.a
PFNAME = libftprintf.a
SRC = main.c instruction_handler.c op.c sup_func.c core.c core_assist.c \
live.c ld.c lld.c ldi.c lldi.c add.c sub.c and.c or.c xor.c aff.c zjmp.c \
fork.c lfork.c st.c sti.c prog_args_handler.c champion_handler.c \
champions_loader.c graphic_init.c graphic_update.c graphic_helper.c \
core_helper.c
OBJ = $(subst .c,.o,$(SRC))
HEADERS = vm.h libft.h ft_prinf.h op.h
FLS = -Wall -Wextra -Werror
VPATH = Includes:Srcs:libft:ft_printf

.PHONY: all clean fclean re

all: $(NAME)

$(NAME) : $(OBJ) $(LIBNAME) $(PFNAME)
	gcc $(FLS) $(OBJ) -o $(NAME) ./libft/$(LIBNAME) ./ft_printf/$(PFNAME) -lncurses

$(LIBNAME) :
	make -C ./libft/

$(PFNAME) :
	make -C ./ft_printf/

%.o: %.c $(HEADERS)
	 gcc $(FLS) -c -o $@ $< -I ./Includes -lncurses

clean:
	/bin/rm -f $(OBJ) *~
	make -C ./libft/ clean
	make -C ./ft_printf/ clean

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all