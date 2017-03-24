/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 16:57:13 by aklimchu          #+#    #+#             */
/*   Updated: 2017/01/11 18:08:49 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		process_spec(const char *format, va_list *args)
{
	int		i;
	char	*str;

	i = 0;
	get_spec_info(format, args);
	while (g_func_arr[i].spec != g_param.spec)
		i++;
	str = (*(g_func_arr[i].f))(args);
	if (!str && format[g_param.i])
	{
		str = ft_strnew(1);
		str[0] = format[g_param.i++];
		g_param.char_num += apply_width(&str, 1, 0);
	}
	ft_putnstr(str, 0);
	free(str);
	erase_params();
}

void		form_iter(const char *format, va_list *args)
{
	while (format[g_param.i])
	{
		if (format[g_param.i] == '%')
		{
			g_param.i++;
			process_spec(format, args);
		}
		else
		{
			write(1, format + g_param.i, 1);
			g_param.char_num++;
			g_param.i++;
		}
	}
	g_param.i = 0;
}

int			ft_printf(const char *format, ...)
{
	va_list args;
	int		char_num;

	va_start(args, format);
	form_iter(format, &args);
	va_end(args);
	char_num = g_param.char_num;
	g_param.char_num = 0;
	return (char_num);
}
