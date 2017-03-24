/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chars_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 18:45:23 by aklimchu          #+#    #+#             */
/*   Updated: 2017/01/11 15:45:58 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*form_wstr(va_list *args)
{
	char			*str;
	unsigned int	*w_str;
	char			*w_char;
	int				i;

	i = 0;
	str = ft_strnew(0);
	if (!(w_str = va_arg(*args, unsigned int*)))
		return (ft_strdup("(null)"));
	while (w_str[i])
	{
		w_char = (char*)get_wchar(w_str[i++]);
		if (g_param.prec &&
			(ft_strlen(str) + ft_strlen(w_char)) > (size_t)g_param.prec_val)
		{
			free(w_char);
			break ;
		}
		str = ft_memrealloc((void**)&str, ft_strlen(str) +
							ft_strlen(w_char) + 1);
		ft_strcat(str, w_char);
		free(w_char);
	}
	return (str);
}

char				*form_str(va_list *args)
{
	char			*str;
	char			*temp_str;

	if (g_param.length == l)
		str = form_wstr(args);
	else
	{
		if (!(temp_str = va_arg(*args, char*)))
			str = ft_strdup("(null)");
		else
			str = ft_strdup(temp_str);
		if (g_param.prec && (size_t)g_param.prec_val < ft_strlen(str))
		{
			str = ft_memrealloc((void**)&str, g_param.prec_val + 1);
			str[g_param.prec_val] = '\0';
		}
	}
	g_param.char_num += apply_width(&str, ft_strlen(str), 0);
	return (str);
}

char				*form_char(va_list *args)
{
	char			*str;
	int				str_sz;

	if (g_param.length == l)
		str = (char*)get_wchar(va_arg(*args, unsigned int));
	else
	{
		str = ft_strnew(1);
		str[0] = va_arg(*args, unsigned int);
	}
	if (!str[0])
	{
		str_sz = apply_width(&str, 1, 0);
		ft_putnstr(str, str_sz);
		g_param.char_num += str_sz;
		return (ft_strnew(0));
	}
	str_sz = ft_strlen(str);
	str_sz = apply_width(&str, str_sz, 0);
	g_param.char_num += str_sz;
	return (str);
}
