/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_argument.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <omartyno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 00:47:29 by omartyno          #+#    #+#             */
/*   Updated: 2017/04/02 09:46:09 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/asmblr.h"

void	add_value_list(char *label, unsigned char type,
						t_prpts *prop, unsigned int place)
{
	t_label		*new;
	t_label		*now;

	new = (t_label *)malloc(sizeof(t_label));
	new->key = label;
	new->line = prop->str_now;
	new->place = place;
	new->null_place = prop->bc;
	new->small = (type == IND_CODE) ? 1 : prop->now->small_label;
	new->next = NULL;
	if (!prop->head)
	{
		prop->head = new;
		return ;
	}
	now = prop->head;
	while (now->next)
		now = now->next;
	now->next = new;
}

void	read_label(char *line, unsigned char type, t_prpts *prop, int byte)
{
	size_t	j;
	char	*label;

	j = 0;
	while (is_lblchar(line[prop->i + j]))
		j++;
	if ((!(ft_iswhitespace(line[prop->i + j])) && line[prop->i + j]
		!= SEPARATOR_CHAR && line[prop->i + j]) || !j)
		go_error((type == DIR_CODE) ? "Bad direct label name\n"
			: "Bad indirect label name\n", prop);
	label = ft_strnew(j);
	j = 0;
	while (is_lblchar(line[prop->i]))
		label[j++] = line[(prop->i)++];
	add_value_list(label, type, prop, prop->bc + (unsigned int)byte);
	while (ft_iswhitespace(line[prop->i]))
		(prop->i)++;
}

int		read_register(char *line, t_prpts *prop)
{
	int		ret;

	ret = ft_atoi(line + prop->i);
	if (ret > REG_NUMBER)
		go_error("Registor number is higher than max\n", prop);
	if (ret < 1)
		go_error("Registor number is lower than 1\n", prop);
	while (ft_isdigit(line[prop->i]))
		(prop->i)++;
	while (ft_iswhitespace(line[prop->i]))
		(prop->i)++;
	return (ret);
}

int		read_dn(char *line, unsigned char type, t_prpts *prop, int byte)
{
	int		ret;

	if (line[prop->i] == LABEL_CHAR && ++(prop->i))
	{
		read_label(line, type, prop, byte);
		return (0);
	}
	ret = ft_atoi(line + prop->i);
	if (line[prop->i] == '-')
		(prop->i)++;
	while (ft_isdigit(line[prop->i]))
		(prop->i)++;
	while (ft_iswhitespace(line[prop->i]))
		(prop->i)++;
	return (ret);
}

t_arg	get_one(char *line, unsigned char type, t_prpts *prop, int byte)
{
	t_arg	ret;

	if (line[(prop->i)] == 'r' && ((type) & T_REG))
	{
		ret.type = REG_CODE;
		(prop->i)++;
		ret.value = read_register(line, prop);
		return (ret);
	}
	if (line[(prop->i)] == DIRECT_CHAR && ((type) & T_DIR))
	{
		ret.type = DIR_CODE;
		(prop->i)++;
		ret.value = read_dn(line, ret.type, prop, byte);
		return (ret);
	}
	if (!(type & T_IND))
		go_error("Wrong argument type for command\n", prop);
	ret.type = IND_CODE;
	ret.value = read_dn(line, ret.type, prop, byte);
	return (ret);
}
