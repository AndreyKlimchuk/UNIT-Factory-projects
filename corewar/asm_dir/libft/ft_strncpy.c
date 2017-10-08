/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 13:36:35 by omartyno          #+#    #+#             */
/*   Updated: 2016/11/22 13:38:29 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned long	i;

	i = 0;
	while (i != n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (i != n)
		dest[i++] = '\0';
	return (dest);
}
