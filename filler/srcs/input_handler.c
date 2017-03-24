/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 13:08:54 by aklimchu          #+#    #+#             */
/*   Updated: 2017/02/19 09:49:08 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_map		*update_map(char **str, t_map *map)
{
	int		row;
	int		col;

	free(*str);
	get_next_line(0, str);
	free(*str);
	row = -1;
	while (map->field[++row])
	{
		col = -1;
		get_next_line(0, str);
		while (++col < map->col)
			if (map->field[row][col].c != (*str)[col + 4])
				map->field[row][col].c = (*str)[col + 4];
		free(*str);
	}
	return (map);
}

t_map		*get_map(char **str, t_map *map)
{
	int		row;
	int		col;

	get_dim(&(map->row), &(map->col), *str);
	free(*str);
	get_next_line(0, str);
	free(*str);
	map->field = (t_cell**)malloc(sizeof(t_cell*) * (map->row + 1));
	map->field[map->row] = NULL;
	row = -1;
	while (++row < map->row)
	{
		map->field[row] = (t_cell*)malloc(sizeof(t_cell) * (map->col + 1));
		get_next_line(0, str);
		col = -1;
		while (++col < map->col)
		{
			map->field[row][col].c = (*str)[col + 4];
			map->field[row][col].weight = INT_MAX;
		}
		map->field[row][col].c = '\0';
		map->field[row][col].weight = 0;
		free(*str);
	}
	return (map);
}

static void	trunc_shape(t_piece *fig, int old_row_num)
{
	int		row;
	char	*new_row;

	row = -1;
	while (++row < fig->row)
	{
		new_row = ft_strsub(fig->shape[row], 0, fig->col);
		free(fig->shape[row]);
		fig->shape[row] = new_row;
	}
	fig->shape[row] = NULL;
	row++;
	while (row <= old_row_num)
	{
		free(fig->shape[row]);
		fig->shape[row] = NULL;
		row++;
	}
}

static void	trunc(t_piece *fig)
{
	int		col;
	int		row;
	int		old_row_num;

	col = fig->col;
	row = fig->row;
	while (col-- && row == fig->row)
	{
		row = -1;
		while (fig->shape[++row])
			if (fig->shape[row][col] == '*')
				break ;
	}
	fig->col = (col += 2);
	row = fig->row;
	while (row-- && col == fig->col)
	{
		col = -1;
		while (++col < fig->col)
			if (fig->shape[row][col] == '*')
				break ;
	}
	old_row_num = fig->row;
	fig->row = row + 2;
	trunc_shape(fig, old_row_num);
}

t_piece		*get_fig(char **str, t_piece *fig)
{
	int		i;

	get_next_line(0, str);
	get_dim(&(fig->row), &(fig->col), *str);
	free(*str);
	fig->shape = (char**)malloc(sizeof(char*) * (fig->row + 1));
	fig->shape[fig->row] = NULL;
	i = 0;
	while (i < fig->row)
	{
		get_next_line(0, str);
		fig->shape[i++] = ft_strdup(*str);
		free(*str);
	}
	trunc(fig);
	return (fig);
}
