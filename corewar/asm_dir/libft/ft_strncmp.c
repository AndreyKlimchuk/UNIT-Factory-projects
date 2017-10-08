/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:18:27 by omartyno          #+#    #+#             */
/*   Updated: 2016/11/24 14:52:33 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int				answer;
	unsigned int	i;

	i = -1;
	answer = 0;
	while (s1[++i] != '\0' && !(answer) && i < (unsigned int)n)
		answer = (int)((unsigned char)s1[i] - (unsigned char)s2[i]);
	answer = (!answer && i != n) ? ((int)((unsigned char)s1[i] -
										(unsigned char)s2[i])) : answer;
	return (answer);
}
