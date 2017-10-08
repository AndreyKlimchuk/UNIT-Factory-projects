/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ophash.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <omartyno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 19:03:47 by omartyno          #+#    #+#             */
/*   Updated: 2017/03/24 17:30:43 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/asmblr.h"

t_ophsh	*g_op_hash[256];

int		get_opind(char *key)
{
	unsigned char	name;
	size_t			i;

	name = 0;
	i = -1;
	while (key[++i])
		name += (unsigned char)key[i];
	return ((int)name);
}

void	add_ophash(t_op *value)
{
	int		ind;
	t_ophsh	*new;
	t_ophsh	*now;

	ind = get_opind(value->name);
	new = (t_ophsh *)malloc(sizeof(t_ophsh));
	new->value = value;
	new->next = NULL;
	if (!(g_op_hash[ind]))
	{
		g_op_hash[ind] = new;
		return ;
	}
	now = g_op_hash[ind];
	while (now->next)
		now = now->next;
	now->next = new;
}

t_op	*get_ophsh(char *key)
{
	int		ind;
	t_ophsh	*now;

	ind = get_opind(key);
	now = g_op_hash[ind];
	if (!now)
		return (NULL);
	if (!now->next)
		return (now->value);
	while (now->next)
	{
		if (ft_strequ(now->value->name, key))
			return (now->value);
		now = now->next;
	}
	return (now->value);
}

void	fill_ophash(void)
{
	int		i;

	i = -1;
	while (++i < 256)
		g_op_hash[i] = NULL;
	i = -1;
	while (g_op_tab[++i].name)
		add_ophash(g_op_tab + i);
}
