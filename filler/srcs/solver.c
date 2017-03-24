/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 14:21:09 by aklimchu          #+#    #+#             */
/*   Updated: 2017/02/19 09:38:50 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			check_chars(t_state *st, char fig_char, char map_char, int *cross)
{
	if (fig_char == '*')
	{
		if (map_char == st->enemy_c || map_char == st->enemy_c + 32)
			return (-1);
		else if (map_char == st->my_c || map_char == st->my_c + 32)
			(*cross)++;
		return (1);
	}
	return (0);
}

int			check_pos(t_state *st, int y, int x)
{
	int		weight;
	int		cross;
	int		row;
	int		col;
	int		ret;

	cross = 0;
	weight = 0;
	row = -1;
	while (++row < st->fig->row)
	{
		col = -1;
		while (++col < st->fig->col)
		{
			if ((ret = check_chars(st, st->fig->shape[row][col],
							st->map->field[y + row][x + col].c,
							&cross)) == -1)
				return (-1);
			else if (ret)
				weight += st->map->field[y + row][x + col].weight;
			if (cross > 1)
				return (-1);
		}
	}
	return ((cross == 1) ? weight : -1);
}

void		calculate_weights(t_map *map, int y, int x)
{
	int		row;
	int		col;
	int		new_weight;

	row = -1;
	map->field[y][x].weight = 0;
	while (++row < map->row)
	{
		col = -1;
		while (++col < map->col)
		{
			new_weight = ft_modi(x - col) + ft_modi(y - row);
			if (map->field[row][col].weight > new_weight)
				map->field[row][col].weight = new_weight;
		}
	}
}

void		weight_the_map(t_state *st)
{
	int		row;
	int		col;

	row = -1;
	while (++row < st->map->row)
	{
		col = -1;
		while (++col < st->map->col)
		{
			if (st->map->field[row][col].c == st->enemy_c ||
				st->map->field[row][col].c == st->enemy_c + 32)
				calculate_weights(st->map, row, col);
		}
	}
}

t_pos		*choose_pos(t_state *st)
{
	int		row;
	int		col;
	int		fig_weight;
	t_pos	*best_pos;

	best_pos = (t_pos*)malloc(sizeof(t_pos));
	best_pos->fig_weight = INT_MAX;
	row = -1;
	while (++row <= st->map->row - st->fig->row)
	{
		col = -1;
		while (++col <= st->map->col - st->fig->col)
		{
			if ((fig_weight = check_pos(st, row, col)) != -1)
			{
				if (best_pos->fig_weight > fig_weight)
				{
					best_pos->y = row;
					best_pos->x = col;
					best_pos->fig_weight = fig_weight;
				}
			}
		}
	}
	return (best_pos);
}
