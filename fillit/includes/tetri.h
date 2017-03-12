/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 13:46:06 by omartyno          #+#    #+#             */
/*   Updated: 2016/12/03 09:35:44 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRI_H
# define TETRI_H

# define PUST '.'
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <little_lib.h>

/*
** count_size -- calculates field size		(make_field.c)
** field_size -- make field (size x size)	(make_field.c)
*/
char			**field_size(int size);
short			count_size(int fig_num);
/*
** saves input into string					(input_output.c)
** printing field to terminal				(input_output.c)
*/
char			*get_input(char *src);
void			print_field(char **field, short size);

/*
** print error and exit						(errors.c)
*/
void			*error(const char *str, int fd, int code);

/*
** makes one 2d-figure						(make_figure.c)
** put a figure in smaller field			(make_figure.c)
*/
char			**one_figure(char *src, short num);
int				smaller(char ***fig, int hgt, int wgt);

/*
**struct with number of figure, it's height, weight and figure itself
*/
typedef struct	s_etos
{
	short		num;
	short		height;
	short		width;
	short		shift;
	char		**figure;
}				t_etos;

/*
** weight and height of figure in 4x4field	(figure_additional.c)
** shift of figure start					(figure_additional.c)
*/
int				get_width(char ***fig);
int				get_height(char ***fig);
int				get_shift(char **fig, int width);
void			fill_fig(short h, short w, short n, t_etos *figure);

/*
** counts number of figures in file			(array_of_tetos.c)
** makes an array from input string			(array_of_tetos.c)
*/
t_etos			*make_array(char *src);
short			count_file(char *src);

/*
** checks possibility of placing fig		(logic.c)
** placing fig								(logic.c)
** erasing fig								(logic.c)
** moving cursor to the first empty cell	(logic.c)
** recursive function that fills field		(logic.c)
*/
short			is_possible(t_etos *fig, char **field, short x, short y);
void			put_f(t_etos *fig, char **field, short x, short y);
void			erase_f(t_etos *fig, char **field, short x, short y);
short			move_cursor(short *i, short *j, char **field, short size);
short			fillit(char **field, t_etos *figs, short size);

#endif
