/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   white_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <omartyno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 19:08:53 by omartyno          #+#    #+#             */
/*   Updated: 2017/03/25 16:26:26 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/asmblr.h"

int		white_string(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		if (!(ft_iswhitespace(str[i++])))
			return (0);
	return (1);
}

void	skip_white_forw(char *str, size_t *i)
{
	while (ft_iswhitespace(str[*i]))
		(*i)++;
}

void	skip_white_back(char *str, size_t *i)
{
	while (ft_iswhitespace(str[*i]))
		(*i)--;
}
