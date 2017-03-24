/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   farm_builder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 10:14:14 by aklimchu          #+#    #+#             */
/*   Updated: 2017/02/12 12:51:08 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char		**check_room(char *str)
{
	int		i;
	int		j;
	char	**arr;

	i = 0;
	arr = ft_strsplit(str, ' ');
	while (*str)
		if (*(str++) == ' ')
			i++;
	if (i != 2)
		return (free_arr(&arr));
	i = 0;
	while (arr[i])
		i++;
	if (i != 3)
		return (free_arr(&arr));
	i = 0;
	j = 0;
	while (++j <= 2)
	{
		while (arr[j][i])
			if (!ft_isdigit(arr[j][i++]))
				return (free_arr(&arr));
	}
	return (arr);
}

char		**check_link(char *str)
{
	char	**arr;
	int		i;
	int		hyphen_num;

	i = -1;
	hyphen_num = 0;
	while (str[++i])
	{
		if (str[i] == ' ')
			return (0);
		if (str[i] == '-')
			hyphen_num++;
	}
	if (hyphen_num != 1)
		return (0);
	i = 0;
	arr = ft_strsplit(str, '-');
	while (arr[i])
		i++;
	if (i != 2)
		return (free_arr(&arr));
	return (arr);
}

char		add_room(char *str, t_farm *farm)
{
	char	**arr;
	t_room	*new_room;

	if (!(arr = check_room(str)) || search_room(farm->rooms, arr[0]))
		return (0);
	new_room = (t_room*)malloc(sizeof(t_room));
	new_room->name = ft_strdup(arr[0]);
	new_room->dist = -1;
	new_room->step = 0;
	new_room->coord[0] = ft_atoi(arr[1]);
	new_room->coord[1] = ft_atoi(arr[2]);
	new_room->link_num = 0;
	new_room->links = NULL;
	ft_lstadd(&(farm->rooms), ft_lstpnew(new_room, sizeof(t_room)));
	free_arr(&arr);
	return (1);
}

char		add_link(char *str, t_farm *farm)
{
	char	**arr;
	t_room	*room1;
	t_room	*room2;

	if (str[0] == '#')
		return (1);
	if (!(arr = check_link(str)))
		return (0);
	room1 = search_room(farm->rooms, arr[0]);
	room2 = search_room(farm->rooms, arr[1]);
	if (!room1 || !room2)
	{
		free_arr(&arr);
		return (0);
	}
	if (!search_link(room1->links, room2))
	{
		ft_lstadd(&(room1->links), ft_lstpnew(room2, sizeof(t_room)));
		room1->link_num += 1;
		ft_lstadd(&(room2->links), ft_lstpnew(room1, sizeof(t_room)));
		room2->link_num += 1;
	}
	free_arr(&arr);
	return (1);
}
