#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/25 13:40:11 by aklimchu          #+#    #+#              #
#    Updated: 2017/02/11 10:01:02 by aklimchu         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a 
SOURCES = ft_atoi.c ft_lstadd.c ft_memchr.c ft_putchar_fd.c ft_strchr.c \
ft_striteri.c ft_strncpy.c ft_strtrim.c ft_bzero.c ft_lstdel.c ft_memcmp.c \
ft_putendl.c ft_strclr.c ft_strjoin.c ft_strnequ.c ft_tolower.c ft_isalnum.c \
ft_lstdelone.c ft_memcpy.c ft_putendl_fd.c ft_strcmp.c ft_strlcat.c \
ft_strnew.c ft_toupper.c ft_isalpha.c ft_lstiter.c	ft_memdel.c ft_putnbr.c	\
ft_strcpy.c	ft_strlen.c	ft_strnstr.c ft_isascii.c ft_lstmap.c ft_memdup.c \
ft_putnbr_fd.c ft_strdel.c ft_strmap.c ft_strrchr.c ft_isdigit.c ft_lstnew.c \
ft_memmove.c ft_putstr.c ft_strdup.c ft_strmapi.c ft_strsplit.c ft_isprint.c \
ft_memalloc.c ft_memset.c ft_putstr_fd.c ft_strequ.c ft_strncat.c ft_strstr.c \
ft_itoa.c ft_memccpy.c ft_putchar.c ft_strcat.c ft_striter.c ft_strncmp.c \
ft_strsub.c ft_memrealloc.c ft_strrev.c get_next_line.c ft_atoll.c \
ft_dlstnew.c ft_dlstadd.c ft_dlstsrch.c ft_dlstdel.c ft_lstaddback.c \
ft_lstdelcont.c ft_rand.c ft_modi.c ft_qksorti.c ft_lstsrch.c ft_lstpnew.c
OBJECTS = $(subst .c,.o,$(SOURCES))
HEADER = libft.h
VPATH = includes:src

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJECTS) 
	ar rc $(NAME) $(OBJECTS) 

.c.o: $(SOURCES) $(HEADER)
	gcc -Wall -Wextra -Werror -c  $< -I ./includes

clean:
	/bin/rm -f $(OBJECTS) *~

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all