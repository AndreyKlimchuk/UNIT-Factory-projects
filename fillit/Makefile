#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: omartyno <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/03 10:38:56 by omartyno          #+#    #+#              #
#    Updated: 2016/12/29 10:07:22 by aklimchu         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit
VPATH = src:includes
SRCS = array_of_tetos.c figure_additional.c ft_putendl_fd.c ft_putstr_fd.c \
logic.c make_field.c errors.c ft_putchar.c ft_putstr.c input_output.c main.c \
make_figure.c
HEADERS = little_lib.h tetri.h
OBJS = $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	gcc -Wall -Wextra -Werror $(OBJS) -o $(NAME)

$(OBJS): $(HEADERS)

.c.o: $(SRCS)
	gcc -Wall -Wextra -Werror -I ./includes -c $<

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
