/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sup_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 17:21:45 by aklimchu          #+#    #+#             */
/*   Updated: 2017/02/19 10:37:56 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		erase_fig(char ***fig)
{
	int		i;

	i = 0;
	while ((*fig)[i])
		free((*fig)[i++]);
	free((*fig)[i]);
	free(*fig);
}

void		get_dim(int *row, int *col, char *str)
{
	int		i;

	i = 0;
	while (!ft_isdigit(str[i]))
		i++;
	*row = ft_atoi(str + i);
	while (ft_isdigit(str[i]))
		i++;
	*col = ft_atoi(str + i + 1);
}

void		print_pos(int x, int y)
{
	ft_putnbr(y);
	ft_putchar(' ');
	ft_putnbr(x);
	ft_putchar('\n');
}

void		del_all(t_state **st)
{
	int		i;

	i = 0;
	while ((*st)->map->field[i])
		free((*st)->map->field[i++]);
	free((*st)->map->field[i]);
	free((*st)->map->field);
	free((*st)->map);
	free((*st)->fig);
	free(*st);
}
