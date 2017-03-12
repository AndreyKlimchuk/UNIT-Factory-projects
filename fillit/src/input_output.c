/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 22:43:15 by omartyno          #+#    #+#             */
/*   Updated: 2016/12/03 12:39:46 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tetri.h>

char		*get_input(char *src)
{
	int		fd;
	short	pos;
	char	*new;

	fd = open(src, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Failed to open a file\n", 2);
		return (0);
	}
	else
	{
		if (!(new = (char *)malloc(551)))
		{
			ft_putstr_fd("Not enough memory\n", 2);
			return (0);
		}
		pos = read(fd, new, 550);
		new[pos] = '\0';
	}
	if (close(fd) == -1)
		error("Can't close file", 2, 1);
	return (new);
}

void		print_field(char **field, short size)
{
	short i;
	short j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			ft_putchar(field[i][j]);
		ft_putchar('\n');
	}
}
