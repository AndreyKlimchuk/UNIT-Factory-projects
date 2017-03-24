/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   painter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 12:22:44 by aklimchu          #+#    #+#             */
/*   Updated: 2017/02/19 14:47:55 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		print_line(char **str)
{
	get_next_line(0, str);
	ft_putstr(*str);
	ft_putchar('\n');
	free(*str);
}

void		print_header(char **str)
{
	write(1, RED, 5);
	get_next_line(0, str);
	while ((*str)[0] == '#')
	{
		ft_putstr(*str);
		ft_putchar('\n');
		free(*str);
		get_next_line(0, str);
	}
	write(1, RESET, 4);
	ft_putstr(*str);
	ft_putchar('\n');
	free(*str);
	write(1, BLU, 5);
	print_line(str);
	write(1, RESET, 4);
	print_line(str);
	write(1, YEL, 5);
	print_line(str);
	write(1, RESET, 4);
}

void		print_row(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'O' || str[i] == 'o')
		{
			write(1, BLU, 5);
			while (str[i] == 'O' || str[i] == 'o')
				write(1, str + i++, 1);
			write(1, RESET, 4);
		}
		else if (str[i] == 'X' || str[i] == 'x')
		{
			write(1, YEL, 5);
			while (str[i] == 'X' || str[i] == 'x')
				write(1, str + i++, 1);
			write(1, RESET, 4);
		}
		else
			write(1, str + i++, 1);
	}
}

int			main(void)
{
	char	*str;
	int		i;

	i = -1;
	print_header(&str);
	while (get_next_line(0, &str))
	{
		if (ft_strstr(str, "got"))
		{
			write(1, GRN, 5);
			ft_putstr(str);
			ft_putchar('\n');
			write(1, RESET, 4);
		}
		else
			print_row(str);
		write(1, "\n", 1);
		free(str);
	}
	return (0);
}
