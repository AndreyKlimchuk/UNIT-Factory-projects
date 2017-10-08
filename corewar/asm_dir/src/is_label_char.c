/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_label_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <omartyno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 18:11:29 by omartyno          #+#    #+#             */
/*   Updated: 2017/03/24 17:19:43 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/asmblr.h"

int		ft_instr(char c, const char *str)
{
	size_t	i;

	i = -1;
	while (str[++i])
		if (str[i] == c)
			return (1);
	return (0);
}

int		is_lblchar(char c)
{
	return (((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')
		|| c == '_') ? 1 : 0);
}
