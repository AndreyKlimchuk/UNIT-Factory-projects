/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putslen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 03:28:31 by omartyno          #+#    #+#             */
/*   Updated: 2016/12/24 05:35:15 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		ft_putslen(char **s)
{
	int		i;

	i = 0;
	while ((*s)[i] && i >= 0)
		i++;
	write(1, *s, i);
	my_free((void **)s);
	return (i);
}

int		just_putslen(const char *s)
{
	int		i;

	i = 0;
	while (s[i] && i >= 0)
		i++;
	write(1, s, i);
	return (i);
}
