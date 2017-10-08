#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omartyno <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/24 01:52:30 by omartyno          #+#    #+#              #
#    Updated: 2016/12/31 17:27:08 by omartyno         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a
VPATH = src:includes
SRC = expands.c ft_strdup.c show_char.c skippers.c ft_freedup.c ft_strlen.c \
show_int.c get_num_funcs.c show_num_base.c wchar_to_str.c ft_printf_main.c \
get_on_point.c show_str.c ft_putslen.c get_on_point_2.c show_str_big.c showf.c \
ft_putstr.c get_wchar.c char_float.c showf_next.c float_f.c float_f_16.c \
char_float_16.c floats_funcs.c floats_funcs_2.c float_e.c pre_format.c \
float_g.c ft_myfree.c ft_putbits.c
HEAD = ft_printf.h
OBJS = $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $@ $?
	ranlib $@

$(OBJS): $(HEAD)

.c.o: $(SRC)
	gcc -Wall -Wextra -Werror -I ./includes -c $<

clean:
	/bin/rm -f $(OBJS)

dellib:
	/bin/rm -f $(NAME)

fclean: clean dellib

re: dellib all