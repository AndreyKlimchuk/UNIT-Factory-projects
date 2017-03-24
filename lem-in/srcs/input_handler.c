/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 11:51:02 by aklimchu          #+#    #+#             */
/*   Updated: 2017/02/12 12:49:31 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			add_mapdesc(char *str, t_farm *farm)
{
	int			total_len;
	int			add_len;

	total_len = (farm->map_desc) ? ft_strlen(farm->map_desc) : 0;
	add_len = ft_strlen(str);
	farm->map_desc = ft_memrealloc(((void**)&(farm->map_desc)),
							total_len + add_len + 2);
	farm->map_desc = ft_strcat(farm->map_desc, str);
	total_len = ft_strlen(farm->map_desc);
	farm->map_desc[total_len] = '\n';
	farm->map_desc[total_len + 1] = '\0';
}

char			process_room(t_farm *farm, char *str, char *flag)
{
	static char	start;
	static char	end;

	if (str[0] == 'L')
		return (0);
	else if (str[0] != '#')
	{
		if (!add_room(str, farm))
			*flag = 1;
		else
		{
			if (start && !(start = 0))
				farm->start = farm->rooms;
			else if (end && !(end = 0))
				farm->end = farm->rooms;
		}
	}
	else
	{
		if (ft_strequ(str, "##start") && !(end = 0))
			start = 1;
		else if (ft_strequ(str, "##end") && !(start = 0))
			end = 1;
	}
	return (1);
}

char			get_unt_num(t_farm *farm, char *str)
{
	long long	num;
	int			i;

	i = -1;
	while (str[++i])
		if (!(ft_isdigit(str[i])))
			return (0);
	if (i > 10 || (num = ft_atoll(str)) > INT_MAX)
		return (0);
	else
		farm->unt_num = (int)num;
	return (1);
}

char			handle_input(t_farm *farm, int fd)
{
	int			i;
	char		*str;
	char		link_flag;
	char		status;

	i = 0;
	link_flag = 0;
	status = 0;
	while (get_next_line(fd, &str))
	{
		if (i == 0)
			status = get_unt_num(farm, str);
		else if (!link_flag)
			status = process_room(farm, str, &link_flag);
		if (link_flag)
			status = add_link(str, farm);
		add_mapdesc(str, farm);
		free(str);
		if (!status)
			return (0);
		i++;
	}
	if (!farm->start || !farm->end || !farm->rooms)
		return (0);
	return (1);
}
