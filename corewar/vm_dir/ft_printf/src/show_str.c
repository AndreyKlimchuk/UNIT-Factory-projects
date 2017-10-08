/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 22:12:40 by omartyno          #+#    #+#             */
/*   Updated: 2016/12/31 13:30:54 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char		*onechar_str(char c, size_t sz)
{
	size_t	i;
	char	*str;

	str = (char *)malloc(sz + 1);
	i = 0;
	while (i < sz)
	{
		str[i] = c;
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*copy_prec(char *str, long long prec)
{
	long long	i;
	long long	slen;
	char		*buf;

	slen = (long long)ft_strlen(str);
	if (slen < 0)
		slen = 0;
	slen = (prec != -1 && prec < slen) ? prec : slen;
	buf = (char *)malloc(1 + slen);
	i = -1;
	while (++i < slen)
		buf[i] = str[i];
	buf[i] = '\0';
	return (buf);
}

int			show_string(t_param *now, char *str)
{
	char	*s_n;
	char	*wid;
	int		out;

	if (!str)
		s_n = copy_prec("(null)", now->prec);
	else
		s_n = copy_prec(str, now->prec);
	out = ((int)ft_strlen(s_n) < 0) ? 0 : (int)ft_strlen(s_n);
	wid = NULL;
	if (now->width != -1 && out < now->width)
	{
		wid = onechar_str((now->flags[1]) ? '0' : ' ',
						(size_t)(now->width - out));
		out = now->width;
	}
	if (wid && !(now->flags[2]))
		ft_putstr(wid);
	ft_putstr(s_n);
	if (wid && now->flags[2])
		ft_putstr(wid);
	my_free((void **)&s_n);
	my_free((void **)&wid);
	return ((out < 0) ? 0 : out);
}
