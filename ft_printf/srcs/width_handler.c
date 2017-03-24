/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 19:59:29 by aklimchu          #+#    #+#             */
/*   Updated: 2017/01/11 18:04:22 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	extend_str(char **str, int padding, int diff, char symb)
{
	int		i;
	char	*new_str;

	i = -1;
	new_str = (char*)malloc(sizeof(char) * (g_param.width_val + 1));
	while (++i < padding)
		new_str[i] = (*str)[i];
	while (diff-- > 0)
		new_str[i++] = symb;
	ft_strcpy(new_str + i, *str + padding);
	free(*str);
	*str = new_str;
	return (g_param.width_val);
}

int			apply_width(char **str, int size, int padding)
{
	char	symb;
	int		diff;
	int		i;

	if (!g_param.width || (g_param.width_val <= size))
		return (size);
	i = 0;
	symb = ' ';
	if ((*str)[0] == '+' || (*str)[0] == '-' || (*str)[0] == ' ')
		padding = 1;
	while (g_func_arr[i].spec != g_param.spec)
		i++;
	if (g_param.flags.zero && !g_param.flags.minus && (!g_param.prec
		|| g_param.prec_val < 0 || g_func_arr[i].f != &form_int_num))
		symb = '0';
	else
	{
		if (g_param.flags.minus)
			padding = size;
		else
			padding = 0;
	}
	diff = g_param.width_val - size;
	return (extend_str(str, padding, diff, symb));
}
