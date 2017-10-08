/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 23:17:05 by omartyno          #+#    #+#             */
/*   Updated: 2017/03/13 02:35:02 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		show_char(unsigned char c, t_param *now)
{
	char	*str;

	if (now->flags[2])
		write(1, &c, 1);
	if (now->width > 1)
	{
		str = onechar_str((now->flags[1]) ? '0' : ' ', now->width - 1);
		ft_putstr(str);
		free(str);
	}
	if (!(now->flags[2]))
		write(1, &c, 1);
	return ((now->width > 1) ? now->width : 1);
}

int		show_wchar(unsigned int c, t_param *now)
{
	char	*onech;
	int		ret;

	if (now->prec != -1)
		now->prec = -1;
	if (c)
	{
		onech = get_wchar(c);
		ret = show_string(now, onech);
	}
	else
	{
		onech = malloc(1);
		onech[0] = '\0';
		if (now->flags[2])
			write(1, onech, 1);
		ret = show_string(now, onech) + 1;
		if (!(now->flags[2]))
			write(1, onech, 1);
	}
	my_free((void **)&onech);
	return (ret);
}
