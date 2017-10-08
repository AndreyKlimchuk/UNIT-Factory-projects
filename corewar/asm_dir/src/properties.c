/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   properties.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <omartyno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 23:54:01 by omartyno          #+#    #+#             */
/*   Updated: 2017/03/22 18:12:15 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/asmblr.h"

t_prpts		*init_prop(void)
{
	t_prpts	*prop;

	prop = (t_prpts *)malloc(sizeof(t_prpts));
	prop->table = init_table(256);
	prop->size = 256;
	prop->str_now = 0;
	prop->str_byte = 0;
	prop->i = 0;
	prop->bc = 0;
	prop->now = NULL;
	prop->head = NULL;
	return (prop);
}

void		free_prop(t_prpts **prop)
{
	t_label		*now;
	t_label		*next;

	now = (*prop)->head;
	while (now)
	{
		next = now->next;
		free(now->key);
		free(now);
		now = next;
	}
	free_table(&((*prop)->table), (*prop)->size);
	free(*prop);
}
