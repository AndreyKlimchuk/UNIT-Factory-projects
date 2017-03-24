#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/28 20:18:26 by aklimchu          #+#    #+#              #
#    Updated: 2017/01/11 15:20:20 by aklimchu         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a
VPATH = srcs:includes
SOURCES = ft_memrealloc.c ft_strnequ.c ft_printf.c ft_strnew.c param_graber.c \
chars_handler.c ft_printf.h wchar_handler.c ft_atoi.c ft_strcat.c ft_putnstr.c\
sup_func.c width_handler.c ft_isdigit.c ft_strcpy.c int_val_handler.c \
ft_memalloc.c ft_strlen.c itoa_converter.c ft_bzero.c ft_strdup.c
OBJECTS = $(subst .c,.o,$(SOURCES))
HEADER = ft_printf.h

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rc $@ $^
	ranlib $@

$(OBJS): $(HEADER)

.c.o: $(SOURCES)
	gcc -Wall -Wextra -Werror -I ./includes -c $<

clean:
	/bin/rm -f $(OBJECTS)

dellib:
	/bin/rm -f $(NAME)

fclean: clean dellib

re: dellib all
