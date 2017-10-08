/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:16:22 by omartyno          #+#    #+#             */
/*   Updated: 2017/01/30 21:13:01 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strcmp(const char *s1, const char *s2)
{
	int		answer;
	size_t	i;

	i = -1;
	answer = 0;
	while (s1[++i] != '\0' && !(answer))
		answer = (int)((unsigned char)s1[i] - (unsigned char)s2[i]);
	answer = (!answer) ? ((int)((unsigned char)s1[i] - (unsigned char)s2[i]))
		: answer;
	return (answer);
}
