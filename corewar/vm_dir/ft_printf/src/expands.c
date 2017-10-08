/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expands.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 03:32:15 by omartyno          #+#    #+#             */
/*   Updated: 2016/12/31 14:06:34 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void		expand_width(char **str, long long wid, char left, char with)
{
	char	*buf;
	size_t	i;
	size_t	len;

	buf = (char *)malloc(wid + 1);
	i = 0;
	while (i < (size_t)wid)
		buf[i++] = with;
	buf[i] = '\0';
	i = 0;
	len = ft_strlen(*str);
	while (i < len)
	{
		if (!left)
			buf[wid - i - 1] = (*str)[len - i - 1];
		else
			buf[i] = (*str)[i];
		i++;
	}
	my_free((void **)str);
	*str = buf;
}

void		expand_alt(char **str, const char *s2)
{
	char	*buf;
	size_t	i;
	size_t	j;

	i = 0;
	while (s2[i] == *str[i])
	{
		i++;
		if (!(s2[i]))
			return ;
	}
	buf = (char *)malloc(ft_strlen(*str) + ft_strlen(s2) + 1);
	j = -1;
	while (s2[++j])
		buf[j] = s2[j];
	i = 0;
	while ((*str)[i])
		buf[j++] = (*str)[i++];
	buf[j] = 0;
	my_free((void **)str);
	*str = buf;
}

void		expand_nulls(char **str, long long wid, size_t skip)
{
	char	*buf;
	size_t	i;
	size_t	nulls;

	buf = (char *)malloc(wid + 1);
	i = -1;
	buf[wid] = '\0';
	while (++i < skip)
		buf[i] = (*str)[i];
	nulls = (size_t)wid - ft_strlen(*str);
	while ((*str)[i])
	{
		buf[nulls + i] = (*str)[i];
		i++;
	}
	while (nulls--)
		buf[skip + nulls] = '0';
	my_free((void **)str);
	*str = buf;
}

void		expand_point(char **str, char bef)
{
	size_t	i;
	char	*new;

	i = 0;
	while ((*str)[i])
		if (((*str)[i++]) == '.')
			return ;
	new = (char *)malloc(ft_strlen(*str) + 2);
	i = -1;
	while ((*str)[++i] != bef)
		new[i] = (*str)[i];
	new[i] = '.';
	while (bef && (*str)[i])
	{
		new[i + 1] = (*str)[i];
		i++;
	}
	new[i + 1] = '\0';
	my_free((void **)str);
	*str = new;
}
