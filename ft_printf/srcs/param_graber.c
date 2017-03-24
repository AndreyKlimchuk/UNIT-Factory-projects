/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_graber.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 12:02:44 by aklimchu          #+#    #+#             */
/*   Updated: 2017/01/11 17:19:29 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_params			g_param = {{FALSE, FALSE, FALSE, FALSE, FALSE},
	FALSE, 0, FALSE, 0, def, '\0', 0, 0};

t_func_ident		g_func_arr[] = {{'s', &form_str}, {'S', &form_str},
	{'p', &form_int_num}, {'d', &form_int_num}, {'D', &form_int_num},
	{'i', &form_int_num}, {'o', &form_int_num}, {'O', &form_int_num},
	{'u', &form_int_num}, {'U', &form_int_num}, {'x', &form_int_num},
	{'X', &form_int_num}, {'b', &form_int_num}, {'B', &form_int_num},
	{'c', &form_char}, {'C', &form_char}, {'%', &form_perc}, {'\0', &gag}};

static t_flag_ident	g_flag_arr[] = {{'-', &(g_param.flags.minus)},
	{'+', &(g_param.flags.plus)}, {'#', &(g_param.flags.hash)},
	{'0', &(g_param.flags.zero)}, {' ', &(g_param.flags.space)},
	{'\0', NULL}};

static char			*g_size_arr[] = {"\0", "hh", "h", "l", "ll",
	"j", "z", NULL};

int					check_flags(const char *format)
{
	int				j;

	j = 0;
	while (g_flag_arr[j].sign)
	{
		if (format[g_param.i] == g_flag_arr[j].sign)
		{
			*(g_flag_arr[j].ptr) = TRUE;
			g_param.i++;
			return (1);
		}
		j++;
	}
	return (0);
}

int					check_length(const char *format)
{
	int				j;

	j = 0;
	while (g_size_arr[j])
	{
		if (ft_strnequ(g_size_arr[j], format + g_param.i,
				ft_strlen(g_size_arr[j])))
		{
			if ((int)g_param.length < j)
				g_param.length = j;
			g_param.i += ft_strlen(g_size_arr[j]);
			return (1);
		}
		j++;
	}
	return (0);
}

int					check_spec(const char *format)
{
	int				j;

	j = 0;
	while (g_func_arr[j].spec)
	{
		if (format[g_param.i] == g_func_arr[j].spec)
		{
			g_param.spec = g_func_arr[j].spec;
			if (g_param.spec == 'D' || g_param.spec == 'O' ||
				g_param.spec == 'U' || g_param.spec == 'B' ||
				g_param.spec == 'C' || g_param.spec == 'S')
				g_param.length = l;
			g_param.i++;
			return (1);
		}
		j++;
	}
	return (0);
}

int					get_val(const char *format, va_list *args)
{
	char			*num;
	size_t			size;
	int				j;

	if (format[g_param.i] == '*')
	{
		g_param.i++;
		return (va_arg(*args, int));
	}
	size = 0;
	while (ft_isdigit(format[g_param.i + size]))
		size++;
	if (size)
	{
		j = 0;
		num = (char*)malloc(sizeof(char) * (size + 1));
		while (size-- > 0)
			num[j++] = format[g_param.i++];
		num[j] = '\0';
		j = ft_atoi(num);
		free(num);
		return (j);
	}
	return (0);
}

void				get_spec_info(const char *format, va_list *args)
{
	while (!check_spec(format))
	{
		if (check_flags(format))
			continue;
		else if (ft_isdigit(format[g_param.i]) || format[g_param.i] == '*')
		{
			g_param.width = TRUE;
			g_param.width_val = get_val(format, args);
			if (g_param.width_val < 0 && (g_param.flags.minus = TRUE))
				g_param.width_val *= -1;
			continue;
		}
		else if (format[g_param.i] == '.')
		{
			g_param.prec = TRUE;
			g_param.i++;
			g_param.prec_val = get_val(format, args);
			continue;
		}
		else if (check_length(format))
			continue;
		else
			break ;
	}
}
