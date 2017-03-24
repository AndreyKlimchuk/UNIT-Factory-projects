#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/25 13:40:11 by aklimchu          #+#    #+#              #
#    Updated: 2017/01/30 16:49:20 by aklimchu         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAMELIB = libft.a 
NAMEPS = push_swap
NAMECH = checker
SRCLIB = ft_atoi.c ft_lstadd.c ft_memchr.c ft_putchar_fd.c ft_strchr.c ft_striteri.c \
ft_strncpy.c ft_strtrim.c ft_bzero.c ft_lstdel.c ft_memcmp.c ft_putendl.c ft_strclr.c \
ft_strjoin.c ft_strnequ.c ft_tolower.c ft_isalnum.c ft_lstdelone.c ft_memcpy.c ft_putendl_fd.c \
ft_strcmp.c ft_strlcat.c ft_strnew.c ft_toupper.c ft_isalpha.c ft_lstiter.c	ft_memdel.c \
ft_putnbr.c	ft_strcpy.c	ft_strlen.c	ft_strnstr.c ft_isascii.c ft_lstmap.c ft_memdup.c \
ft_putnbr_fd.c ft_strdel.c ft_strmap.c ft_strrchr.c ft_isdigit.c ft_lstnew.c ft_memmove.c \
ft_putstr.c ft_strdup.c ft_strmapi.c ft_strsplit.c ft_isprint.c ft_memalloc.c ft_memset.c \
ft_putstr_fd.c ft_strequ.c ft_strncat.c ft_strstr.c ft_itoa.c ft_memccpy.c ft_putchar.c \
ft_strcat.c ft_striter.c ft_strncmp.c ft_strsub.c ft_memrealloc.c ft_strrev.c get_next_line.c \
ft_atoll.c ft_dlstnew.c ft_dlstadd.c ft_dlstsrch.c ft_dlstdel.c ft_lstaddback.c ft_lstdelcont.c \
ft_randi.c ft_modi.c ft_qksorti.c
SRCPS = push_swap.c sup_func.c opers.c quick_sort.c push_swap_assist.c
SRCCH = checker.c debbuger.c sup_func.c opers.c
OBJLIB = $(subst .c,.o,$(SRCLIB))
OBJPS = $(subst .c,.o,$(SRCPS))
OBJCH = $(subst	.c,.o,$(SRCCH))
HEADERS = libft.h push_swap.h
FLS = -Wall -Wextra -Werror
VPATH = includes:libft:src

.PHONY: all cleanlib clean fclean re

all: $(NAMELIB) $(NAMEPS) $(NAMECH)

$(NAMELIB): $(OBJLIB) 
	ar rc $(NAMELIB) $(OBJLIB)

$(NAMEPS): $(OBJPS) $(NAMELIB)
	gcc $(FLS) $(OBJPS) -o $(NAMEPS) $(NAMELIB)

$(NAMECH): $(OBJCH) $(NAMELIB)
	gcc $(FLS) $(OBJCH) -o $(NAMECH) $(NAMELIB)

%.o: %.c $(HEADERS)
	gcc $(FLS) -c -o $@ $< -I ./includes

cleanlib:
	/bin/rm -f $(NAMELIB)

clean:
	/bin/rm -f $(OBJLIB) $(OBJPS) $(OBJCH) *~

fclean: clean
	/bin/rm -f $(NAMEPS) $(NAMECH) $(NAMELIB)

re: fclean all