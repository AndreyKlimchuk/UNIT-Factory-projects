/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sup_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 09:54:16 by aklimchu          #+#    #+#             */
/*   Updated: 2017/01/11 18:12:13 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		erase_params(void)
{
	g_param.flags.minus = FALSE;
	g_param.flags.plus = FALSE;
	g_param.flags.hash = FALSE;
	g_param.flags.zero = FALSE;
	g_param.flags.space = FALSE;
	g_param.width = FALSE;
	g_param.width_val = 0;
	g_param.prec = FALSE;
	g_param.prec_val = 0;
	g_param.length = 0;
	g_param.spec = '\0';
}

char		*gag(va_list *args)
{
	(void)args;
	return (NULL);
}

char		*form_perc(va_list *args)
{
	char	*str;

	(void)args;
	str = ft_strnew(1);
	str[0] = '%';
	apply_width(&str, 1, 0);
	g_param.char_num += ft_strlen(str);
	return (str);
}
