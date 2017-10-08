/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 13:56:47 by omartyno          #+#    #+#             */
/*   Updated: 2016/11/23 22:50:23 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	unsigned long i;
	unsigned long last;

	i = 0;
	last = 0;
	while (s[++i])
		if (s[i] == (char)c)
			last = i;
	if (!c)
		return ((char *)(s + i));
	if (!last)
		return ((s[0] == (char)(c)) ? (char *)s : 0);
	return ((char *)(s + last));
}
