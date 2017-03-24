/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 17:24:15 by aklimchu          #+#    #+#             */
/*   Updated: 2017/02/19 14:48:13 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"

# define RED   "\x1B[31m"
# define GRN   "\x1B[32m"
# define YEL   "\x1B[33m"
# define BLU   "\x1B[34m"
# define MAG   "\x1B[35m"
# define CYN   "\x1B[36m"
# define WHT   "\x1B[37m"
# define RESET "\x1B[0m"

typedef struct	s_pos
{
	int			y;
	int			x;
	int			fig_weight;
}				t_pos;

typedef struct	s_cell
{
	char		c;
	int			weight;
}				t_cell;

typedef struct	s_piece
{
	char		**shape;
	int			row;
	int			col;
}				t_piece;

typedef struct	s_map
{
	t_cell		**field;
	int			row;
	int			col;
}				t_map;

typedef	struct	s_state
{
	char		my_c;
	char		enemy_c;
	t_piece		*fig;
	t_map		*map;
}				t_state;

t_map			*get_map(char **str, t_map *map);
t_piece			*get_fig(char **str, t_piece *fig);
t_map			*update_map(char **str, t_map *map);
void			get_dim(int *row, int *col, char *str);
void			weight_the_map(t_state *st);
t_pos			*choose_pos(t_state *st);
void			erase_fig(char ***fig);
void			del_all(t_state **st);
void			print_pos(int x, int y);

#endif
