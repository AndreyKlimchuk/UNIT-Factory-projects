/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <omartyno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 17:30:17 by omartyno          #+#    #+#             */
/*   Updated: 2017/04/02 10:00:00 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/asmblr.h"

int		open_err(char *prog, char *name, char *err)
{
	ft_putstr_fd(prog, 2);
	write(2, ": ", 2);
	if (name)
	{
		ft_putstr_fd(name, 2);
		write(2, ": ", 2);
	}
	ft_putstr_fd(err, 2);
	write(2, "\n", 1);
	return (1);
}

int		usage_err(char *prog)
{
	ft_putstr("Usage: ");
	ft_putstr(prog);
	ft_putstr(" <sourcefile.s>\n");
	return (0);
}

int		main(int argc, char **argv)
{
	int			fd_init;
	t_header	head;
	t_prpts		*prop;

	if (argc < 2)
		return (usage_err(argv[0]));
	if ((fd_init = open(argv[argc - 1], O_RDONLY)) < 0)
		return (open_err(argv[0], argv[argc - 1], strerror(errno)));
	prop = init_prop();
	make_nc(&head, fd_init, prop);
	fill_ophash();
	start_write(head, fd_init, argv[argc - 1], prop);
	free_prop(&prop);
}
