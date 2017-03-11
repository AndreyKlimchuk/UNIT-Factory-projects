/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 15:08:38 by aklimchu          #+#    #+#             */
/*   Updated: 2016/11/27 17:57:55 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordnum(char const *s, char c)
{
	int		i;
	int		num;

	i = 0;
	num = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			num++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (num);
}

static int	ft_wordcpy(char **str, char const *s, int start, char c)
{
	int		end;
	int		k;

	end = start;
	k = 0;
	while (s[end] != c && s[end])
		end++;
	if ((*str = (char*)malloc(sizeof(char) * (end - start + 1))))
	{
		while (start < end)
			(*str)[k++] = s[start++];
		(*str)[k] = '\0';
	}
	else
		while (start < end)
			start++;
	return (start);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		idx;
	char	**arr;

	i = 0;
	idx = 0;
	if (!s || !(arr = (char**)malloc(sizeof(char*) * ft_wordnum(s, c) + 1)))
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			i = ft_wordcpy((arr + idx), s, i, c);
			idx++;
		}
		else
			i++;
	}
	arr[idx] = NULL;
	return (arr);
}
