/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   showf.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 16:56:31 by omartyno          #+#    #+#             */
/*   Updated: 2016/12/31 17:22:01 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

enum e_lgths;

static int	pre_num(t_param *now, va_list args, int b, const char *alt)
{
	if (!(now->lgths))
		return (show_num(va_arg(args, unsigned int), now, b, alt));
	if (now->lgths == l)
		return (show_num(va_arg(args, unsigned long), now, b, alt));
	if (now->lgths == ll)
		return (show_num(va_arg(args, unsigned long long), now, b, alt));
	if (now->lgths == h)
		return (show_num((unsigned short)va_arg(args, int), now, b, alt));
	if (now->lgths == hh)
		return (show_num((unsigned char)va_arg(args, int), now, b, alt));
	if (now->lgths == z)
		return (show_num(va_arg(args, size_t), now, b, alt));
	if (now->lgths == j)
		return (show_num(va_arg(args, uintmax_t), now, b, alt));
	return (0);
}

static int	pre_int(t_param *now, va_list args)
{
	if (!(now->lgths))
		return (show_int(va_arg(args, int), now));
	if (now->lgths == l)
		return (show_int(va_arg(args, long), now));
	if (now->lgths == ll)
		return (show_int(va_arg(args, long long), now));
	if (now->lgths == h)
		return (show_int((short)va_arg(args, int), now));
	if (now->lgths == hh)
		return (show_int((char)va_arg(args, int), now));
	if (now->lgths == z)
		return (show_int(va_arg(args, long long), now));
	if (now->lgths == j)
		return (show_int(va_arg(args, intmax_t), now));
	return (0);
}

static int	put_out(int *point, int output)
{
	if (point)
		*point = output;
	return (0);
}

int			show_formatted(t_param *now, va_list args, int out)
{
	if (now->type == 'n')
		return (put_out(va_arg(args, int *), out));
	pre_format(now, args);
	if (now->type == 'S' || (now->type == 's' && now->lgths == l))
		return (show_bigstr(now, va_arg(args, unsigned int *)));
	if (now->type == 's')
		return (show_string(now, va_arg(args, char *)));
	if (now->type == 'd' || now->type == 'i' || now->type == 'D')
		return (pre_int(now, args));
	if (now->type == 'o' || now->type == 'O')
		return (pre_num(now, args, 8, "0"));
	if (now->type == 'u' || now->type == 'U')
		return (pre_num(now, args, 10, ""));
	if (now->type == 'x' || now->type == 'X' || now->type == 'p')
		return (pre_num(now, args, 16, (now->type == 'X') ? "0X" : "0x"));
	if (now->type == 'C' || (now->type == 'c' && now->lgths == l))
		return (show_wchar(va_arg(args, unsigned int), now));
	if (now->type == 'c')
		return (show_char((unsigned char)va_arg(args, int), now));
	if (!now->type)
		return (show_string(now, ""));
	return (show_formatted_next(now, args));
}
