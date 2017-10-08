/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_on_point_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 01:25:10 by omartyno          #+#    #+#             */
/*   Updated: 2016/12/26 16:59:10 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char				g_flags[] = "#0-+ '";
char				g_floats[] = "eEaAfFeE";
enum lgths;

int					get_flags(char c, t_param *now)
{
	short j;

	j = -1;
	while (g_flags[++j])
	{
		if (g_flags[j] == c)
		{
			(now->flags)[j] = 1;
			return (1);
		}
	}
	return (0);
}

static int			one_of(char type)
{
	int i;

	i = 0;
	while (g_floats[i] && g_floats[i] != type)
		i++;
	return ((int)(g_floats[i]));
}

int					get_lgths(const char *src, t_param *now)
{
	if (*src == 'L' && one_of(now->type))
		now->lgths = LL;
	if (*src == 'h' && *(src + 1) == 'h')
	{
		if (now->lgths < hh)
			now->lgths = hh;
		return (1);
	}
	if (*src == 'l' && *(src + 1) == 'l')
	{
		if (now->lgths < ll)
			now->lgths = ll;
		return (1);
	}
	if (*src == 'h' && now->lgths < h)
		now->lgths = h;
	if (*src == 'j' && now->lgths < j)
		now->lgths = j;
	if (*src == 'l' && now->lgths < l)
		now->lgths = l;
	if (*src == 'z' && now->lgths < z)
		now->lgths = z;
	return (0);
}
