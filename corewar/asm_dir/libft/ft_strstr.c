/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 21:56:13 by omartyno          #+#    #+#             */
/*   Updated: 2016/11/22 21:56:18 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	slen(const char *s)
{
	int	len;

	len = -1;
	while (s[++len])
		;
	return (len);
}

char		*ft_strstr(const char *big, const char *lil)
{
	int i;
	int j;

	if (!slen(lil))
		return ((char *)big);
	i = 0;
	while (big[i + slen(lil) - 1] && big[i])
	{
		if (big[i] == *lil)
		{
			j = 0;
			while (big[i + j] == lil[j] && big[i + j])
				j++;
			if (j == slen(lil))
				return ((char *)&big[i]);
		}
		i++;
	}
	return (0);
}
