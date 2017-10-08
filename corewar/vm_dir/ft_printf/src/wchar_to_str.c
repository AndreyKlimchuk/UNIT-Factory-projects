/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar_to_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 23:44:10 by omartyno          #+#    #+#             */
/*   Updated: 2016/12/24 05:54:49 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char		*join_n_free(char **s1, char **s2)
{
	char	*buf;
	size_t	i;
	size_t	j;

	if (!(*s1) || !(*s2) || !s1 || !s2)
		return (NULL);
	buf = (char *)malloc(ft_strlen(*s1) + ft_strlen(*s2) + 1);
	i = -1;
	while ((*s1)[++i])
		buf[i] = (*s1)[i];
	j = 0;
	while ((*s2)[j])
		buf[i++] = (*s2)[j++];
	buf[i] = '\0';
	free(*s1);
	free(*s2);
	*s1 = buf;
	return (*s1);
}

char		*wchar_to_str(unsigned int **str)
{
	char	*onecb;
	char	*all;
	size_t	i;

	all = ft_strdup("");
	i = 0;
	while ((*str)[i])
	{
		onecb = get_wchar((*str)[i++]);
		join_n_free(&all, &onecb);
	}
	free(*str);
	return (all);
}
