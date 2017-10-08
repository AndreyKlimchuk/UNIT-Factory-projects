/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_on_point.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 01:21:25 by omartyno          #+#    #+#             */
/*   Updated: 2016/12/31 17:00:21 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char				g_types[] = "sSpdDioOuUxXcCneEfFgGaA";
char				g_other[] = "'#0-+ 123456789*.hljzL";

size_t				get_type_len(const char *src, t_param *now)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (src[i])
	{
		j = 0;
		while (g_other[j] != src[i] && g_other[j])
			j++;
		if (g_other[j])
			i++;
		else
			break ;
	}
	now->type = src[i];
	now->slen = (now->type) ? i + 2 : i + 1;
	return (i);
}

long long			get_prec(const char *src, t_param *now)
{
	size_t	i;

	i = now->slen;
	while (--i)
		if (src[i] == '.')
		{
			now->prec = get_nns(src + i + 1, (long long)i + 1);
			return (now->prec);
		}
	now->prec = -1;
	return (now->prec);
}

long long			get_widt(const char *src, t_param *now)
{
	size_t	i;
	size_t	last;

	i = 0;
	last = 0;
	now->wis = 0;
	while (i < now->slen)
	{
		if (src[i] == '.' && ++i)
			i += skip_snn(src + i);
		if ((src[i] >= '1' && src[i] <= '9') || src[i] == '*')
		{
			if (src[i] == '*')
				(now->wis)++;
			last = i;
			i += skip_snn(src + i) - 1;
		}
		if (src[i] != '.' && src[i])
			i++;
	}
	if (!last)
		now->width = -1;
	else
		now->width = get_nns(src + last, (long long)last);
	return (now->width);
}

static t_param		*clear_param(void)
{
	t_param	*ret;
	short	i;

	ret = (t_param *)malloc(sizeof(t_param));
	ret->flags = (char *)malloc(5);
	i = 0;
	while (i < 5)
		(ret->flags)[i++] = '\0';
	ret->lgths = 0;
	ret->next = NULL;
	return (ret);
}

t_param				*get_on_point(const char *src)
{
	t_param	*ret;
	size_t	i;

	ret = clear_param();
	get_type_len(src, ret);
	get_prec(src - 1, ret);
	get_widt(src - 1, ret);
	i = 0;
	if (ret->slen < 3)
		return (ret);
	while (i < ret->slen - 2)
	{
		if (src[i] == '.' && ++i)
			i += skip_snn(src + i);
		if (src[i] >= '1' && src[i] <= '9')
			i += skip_num(src + i);
		if (!(get_flags(src[i], ret)))
			i += get_lgths(src + i, ret);
		if (src[i] != '.' && src[i])
			i++;
	}
	return (ret);
}
