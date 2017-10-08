/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <omartyno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 19:54:51 by omartyno          #+#    #+#             */
/*   Updated: 2017/03/24 17:21:05 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/asmblr.h"

t_entry			**init_table(int size)
{
	t_entry		**ret;
	size_t		i;

	if (size < 0)
		return (NULL);
	ret = (t_entry **)malloc(sizeof(t_entry *) * size);
	i = 0;
	while (i < (size_t)size)
		ret[i++] = NULL;
	return (ret);
}

void			free_table(t_entry ***table, int size)
{
	size_t	i;
	t_entry	*now;
	t_entry	*next;

	i = 0;
	while (i < (size_t)size)
	{
		if ((*table)[i])
		{
			now = (*table)[i];
			while (now)
			{
				next = now->next;
				free(now->key);
				free(now);
				now = next;
			}
			(*table)[i] = NULL;
		}
		i++;
	}
	free(*table);
}

int				get_index(char *key, int size)
{
	int		name;
	size_t	i;

	name = 0;
	i = 0;
	while (key[i])
		name += (int)key[i++];
	name = MOD(name);
	return (name % size);
}

void			add_value(t_entry **table, int size, char *key,
												unsigned int value)
{
	int		ind;
	t_entry	*new;
	t_entry	*now;

	ind = get_index(key, size);
	new = (t_entry *)malloc(sizeof(t_entry));
	new->key = key;
	new->value = value;
	new->next = NULL;
	if (!table[ind])
		table[ind] = new;
	if (table[ind] == new)
		return ;
	now = table[ind];
	while (now->next)
	{
		if (ft_strequ(now->key, key))
		{
			free(key);
			free(new);
			return ;
		}
		now = now->next;
	}
	now->next = new;
}

unsigned int	*get_value(char *key, t_entry **table, int size)
{
	int		ind;
	t_entry	*now;

	ind = get_index(key, size);
	now = table[ind];
	if (!now)
		return (NULL);
	if (!now->next)
		return (&(now->value));
	while (now->next)
	{
		if (ft_strequ(now->key, key))
			return (&(now->value));
		now = now->next;
	}
	return (&(now->value));
}
