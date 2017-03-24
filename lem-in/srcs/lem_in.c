/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 13:58:02 by aklimchu          #+#    #+#             */
/*   Updated: 2017/02/12 13:39:00 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			main(int argc, char **argv)
{
	t_farm	*farm;
	int		fd;

	if (argc > 1)
		fd = open(argv[1], O_RDWR, 777);
	else
		fd = 0;
	farm = (t_farm*)malloc(sizeof(t_farm));
	farm->unt_num = 0;
	farm->map_desc = NULL;
	farm->start = NULL;
	farm->end = NULL;
	farm->rooms = NULL;
	if (fd < 0 || !handle_input(farm, fd) || !solve(farm))
	{
		write(1, "ERROR\n", 6);
		destroy_farm(&farm);
		return (0);
	}
	destroy_farm(&farm);
	return (0);
}
