/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   showf_next.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 17:04:04 by omartyno          #+#    #+#             */
/*   Updated: 2016/12/31 17:24:47 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

enum e_lgths;

static long double	get_arg(t_param *now, va_list args)
{
	long double	pam;

	if (now->lgths == LL)
		pam = va_arg(args, long double);
	else
		pam = va_arg(args, double);
	return (pam);
}

static int			bits(int num, t_param *now)
{
	return (show_string(now, ft_putbits(&num, sizeof(num))));
}

int					show_formatted_next(t_param *now, va_list args)
{
	if (now->type == 'a' || now->type == 'A')
		return (float_f_16(get_arg(now, args), now));
	if (now->type == 'e' || now->type == 'E')
		return (float_e(get_arg(now, args), now));
	if (now->type == 'g' || now->type == 'G')
		return (float_g(get_arg(now, args), now));
	if (now->type == 'f' || now->type == 'F')
		return (float_f(get_arg(now, args), now));
	if (now->type == 'b')
		return (bits(va_arg(args, int), now));
	return (show_char(now->type, now));
}
