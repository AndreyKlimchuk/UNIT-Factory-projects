/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_it_all.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 15:54:10 by aklimchu          #+#    #+#             */
/*   Updated: 2017/01/11 16:31:57 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_dig_ident	g_dig_conv[] = {{'b', 2}, {'B', 2}, {'o', 8}, {'O', 8},
	{'i', 10}, {'d', 10}, {'D', 10}, {'u', 10}, {'U', 10}, {'x', 16}, {'X', 16},
	{'p', 16}};

static intmax_t		get_arg(va_list *args)
{
	if (g_param.length == hh)
		return ((signed char)va_arg(*args, int));
	else if (g_param.length == h)
		return ((short int)va_arg(*args, int));
	else if (g_param.length == l)
		return (va_arg(*args, long int));
	else if (g_param.length == ll)
		return (va_arg(*args, long long int));
	else if (g_param.length == j)
		return (va_arg(*args, intmax_t));
	else if (g_param.length == z)
		return (va_arg(*args, size_t));
	else
		return (va_arg(*args, int));
}

static uintmax_t	get_arg_u(va_list *args)
{
	if (g_param.spec == 'p')
		return ((uintmax_t)(va_arg(*args, void*)));
	else if (g_param.length == hh)
		return ((unsigned char)va_arg(*args, int));
	else if (g_param.length == h)
		return ((unsigned short int)va_arg(*args, int));
	else if (g_param.length == l)
		return (va_arg(*args, unsigned long int));
	else if (g_param.length == ll)
		return (va_arg(*args, unsigned long long int));
	else if (g_param.length == j)
		return (va_arg(*args, uintmax_t));
	else if (g_param.length == z)
		return (va_arg(*args, size_t));
	else
		return (va_arg(*args, unsigned int));
}

static void			apply_prec_int(char **str)
{
	int				diff;
	char			*new_str;
	int				j;
	int				s;

	if (g_param.prec)
	{
		s = 0;
		if ((*str)[0] == '+' || (*str)[0] == '-' || (*str)[0] == ' ')
			s = 1;
		diff = g_param.prec_val - ft_strlen(*str + s);
		if (diff > 0)
		{
			new_str = (char*)malloc(sizeof(char) * (g_param.prec_val + 1));
			j = 0;
			if (s)
				new_str[j++] = (*str)[0];
			while (diff-- > 0)
				new_str[j++] = '0';
			ft_strcpy(new_str + j, *str + s);
			free(*str);
			*str = new_str;
		}
	}
}

static int			add_prefix(char **str, t_bool zero)
{
	char			*new_str;
	char			*prefix;
	int				prefix_size;

	prefix = NULL;
	if ((g_param.spec == 'o' || g_param.spec == 'O') && g_param.flags.hash &&
		(*str)[0] != '0')
		prefix = "0";
	else if ((g_param.spec == 'x' && g_param.flags.hash) || g_param.spec == 'p')
		prefix = "0x";
	else if (g_param.spec == 'X' && g_param.flags.hash)
		prefix = "0X";
	prefix_size = (prefix) ? ft_strlen(prefix) : 0;
	if (prefix && (!zero || g_param.spec == 'p' ||
			((g_param.spec == 'O' || g_param.spec == 'o') && g_param.prec)))
	{
		new_str = (char*)malloc(sizeof(char) *
								(ft_strlen(*str) + prefix_size + 1));
		ft_strcpy(new_str, prefix);
		ft_strcpy(new_str + prefix_size, *str);
		free(*str);
		*str = new_str;
	}
	return (prefix_size);
}

char				*form_int_num(va_list *args)
{
	char			*str;
	short			base;
	int				i;
	int				prefix_size;
	t_bool			zero;

	zero = FALSE;
	i = 0;
	while (g_param.spec != g_dig_conv[i].spec)
		i++;
	base = g_dig_conv[i].base;
	if ((g_param.spec == 'd' || g_param.spec == 'D' || g_param.spec == 'i'))
		str = itoa_base(get_arg(args), base, &zero);
	else
		str = uitoa_base(get_arg_u(args), base, &zero);
	apply_prec_int(&str);
	prefix_size = add_prefix(&str, zero);
	apply_width(&str, ft_strlen(str), prefix_size);
	g_param.char_num += ft_strlen(str);
	return (str);
}
