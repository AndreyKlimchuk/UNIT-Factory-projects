/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sup_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 14:52:06 by aklimchu          #+#    #+#             */
/*   Updated: 2017/02/12 13:26:21 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char		search_link(t_list *links, t_room *room)
{
	while (links)
	{
		if (((t_room*)links->content) == room)
			return (1);
		links = links->next;
	}
	return (0);
}

t_room		*search_room(t_list *rooms, char *name)
{
	while (rooms)
	{
		if (ft_strequ(((t_room*)rooms->content)->name, name))
			return ((t_room*)rooms->content);
		rooms = rooms->next;
	}
	return (NULL);
}

char		**free_arr(char ***arr)
{
	int		i;

	i = 0;
	if (**arr)
	{
		while ((*arr)[i])
			free((*arr)[i++]);
		free(*arr);
	}
	return (NULL);
}

void		destroy_farm(t_farm **farm)
{
	t_list	*temp_node;
	t_list	*temp_link;
	t_list	*curr_link;

	while ((*farm)->rooms)
	{
		free(((t_room*)((*farm)->rooms->content))->name);
		curr_link = ((t_room*)((*farm)->rooms->content))->links;
		while (curr_link)
		{
			temp_link = curr_link;
			curr_link = curr_link->next;
			free(temp_link);
		}
		temp_node = (*farm)->rooms;
		(*farm)->rooms = (*farm)->rooms->next;
		free(temp_node->content);
		free(temp_node);
	}
	free((*farm)->map_desc);
	free(*farm);
}
