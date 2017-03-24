/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_converter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 13:25:20 by aklimchu          #+#    #+#             */
/*   Updated: 2017/01/10 17:02:01 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static short	get_reminders(uintmax_t n, short base, short **rem_arr)
{
	short		i;

	i = 0;
	*rem_arr = (short*)malloc(sizeof(short) * 64);
	while (n >= (uintmax_t)base)
	{
		(*rem_arr)[i++] = n % base;
		n /= base;
	}
	(*rem_arr)[i] = n % base;
	return (i);
}

static char		*choose_reg(void)
{
	if (g_param.spec >= 'A' && g_param.spec <= 'Z')
		return (ft_strdup("0123456789ABCDEF"));
	else
		return (ft_strdup("0123456789abcdef"));
}

static char		*create_str(short **rem_arr, short i, t_bool neg, short base)
{
	char		*str;
	short		j;
	char		*symb;

	j = 0;
	if ((neg || g_param.flags.space || g_param.flags.plus) && base == 10)
		str = (char*)malloc(sizeof(char) * (i + 3));
	else
		str = (char*)malloc(sizeof(char) * (i + 2));
	if (base == 10 && g_param.spec != 'u' && g_param.spec != 'U')
	{
		if (neg)
			str[j++] = '-';
		else if (g_param.flags.plus)
			str[j++] = '+';
		else if (g_param.flags.space)
			str[j++] = ' ';
	}
	symb = choose_reg();
	while (i >= 0)
		str[j++] = symb[(*rem_arr)[i--]];
	str[j] = '\0';
	free(*rem_arr);
	free(symb);
	return (str);
}

char			*itoa_base(intmax_t n, short base, t_bool *zero)
{
	t_bool		neg;
	short		*rem_arr;
	short		i;

	neg = FALSE;
	if (n < 0)
	{
		neg = TRUE;
		n *= -1;
	}
	if (n == 0)
		*zero = TRUE;
	if (*zero && g_param.prec && !g_param.prec_val)
		return (ft_strnew(0));
	else
	{
		i = get_reminders(n, base, &rem_arr);
		return (create_str(&rem_arr, i, neg, base));
	}
}

char			*uitoa_base(uintmax_t n, short base, t_bool *zero)
{
	t_bool		neg;
	short		*rem_arr;
	short		i;

	neg = FALSE;
	if (n == 0)
		*zero = TRUE;
	if (*zero && g_param.prec && !g_param.prec_val)
		return (ft_strnew(0));
	else
	{
		i = get_reminders(n, base, &rem_arr);
		return (create_str(&rem_arr, i, neg, base));
	}
}
