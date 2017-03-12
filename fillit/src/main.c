/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 22:27:19 by omartyno          #+#    #+#             */
/*   Updated: 2016/12/03 12:09:05 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tetri.h>

static int	usage(char *name)
{
	ft_putstr("usage: ");
	ft_putstr(name);
	ft_putstr(" target_file\n");
	return (1);
}

int			main(int argc, char **argv)
{
	char	*str;
	char	**field;
	short	size;
	t_etos	*figs;

	if (argc != 2)
		return (usage(argv[0]));
	if (!(str = get_input(argv[1])))
		return (1);
	if (!(figs = make_array(str)))
		return (1);
	size = count_size(count_file(str));
	if (!(field = field_size(size)))
		return (1);
	while (!fillit(field, figs, size))
	{
		free(field);
		if (!(field = field_size(++size)))
			return (1);
	}
	print_field(field, size);
	return (0);
}
