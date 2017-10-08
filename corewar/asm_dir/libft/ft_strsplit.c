/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 19:02:38 by omartyno          #+#    #+#             */
/*   Updated: 2017/02/27 19:39:01 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	cw(char const *s, char c)
{
	int		wrds;
	int		i;

	i = 0;
	wrds = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			wrds++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (wrds);
}

static int	sow(char const *s, char c)
{
	int	size;

	size = 0;
	while (s[size] && s[size] != c)
		size++;
	return (size);
}

static char	*nw_w(char const *s, char c)
{
	int		ctr;
	int		size;
	char	*new;

	ctr = 0;
	size = sow(s, c);
	new = (char *)malloc(sizeof(char) * (size + 1));
	while (s[ctr] && s[ctr] != c)
	{
		new[ctr] = s[ctr];
		ctr++;
	}
	new[ctr] = 0;
	return (new);
}

char		**ft_strsplit(char const *s, char c)
{
	char		**words;
	size_t		i;
	size_t		j;
	int			nw;

	if (!(s))
		return (0);
	nw = cw(s, c);
	if (!(words = (char **)malloc(sizeof(char *) * (nw + 1))))
		return (0);
	i = 0;
	j = 0;
	while (s[j])
	{
		while (s[j] == c)
			j++;
		if (!s[j])
			break ;
		words[i] = nw_w(s + j, c);
		i++;
		while (s[j] != c && s[j])
			j++;
	}
	words[i] = 0;
	return (words);
}
