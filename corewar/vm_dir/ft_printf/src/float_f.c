/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 17:32:29 by omartyno          #+#    #+#             */
/*   Updated: 2016/12/29 21:02:14 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int			ret_notf(long double z, t_param *now)
{
	int big;

	big = (now->type >= 'A' && now->type <= 'Z');
	now->prec = -1;
	now->flags[1] = 0;
	if (!(z == z))
		return (show_string(now, (big) ? "NAN" : "nan"));
	if (z < 0)
		return (show_string(now, (big) ? "-INF" : "-inf"));
	return (show_string(now, (big) ? "INF" : "inf"));
}

int			sh_num_flags(char **sum, t_param *now, long double z, char sym)
{
	if (z < 0 || now->flags[3])
		expand_alt(sum, (z < 0) ? "-" : "+");
	else if (now->flags[4])
		expand_alt(sum, " ");
	if (now->flags[0])
		expand_point(sum, sym);
	if (now->width < 0 || ft_strlen(*sum) >= (size_t)now->width)
		return (ft_putslen(sum));
	if (!now->flags[1])
		expand_width(sum, now->width, now->flags[2], ' ');
	else
		expand_nulls(sum, now->width, now->flags[3] || z < 0 || now->flags[4]);
	return (ft_putslen(sum));
}

int			float_f(long double z, t_param *now)
{
	char	*sum;

	if (!(z == z) || z == (long double)INFINITY || z == (long double)-INFINITY)
		return (ret_notf(z, now));
	if (now->prec == -1)
		now->prec = 6;
	sum = ch_float(z, now->prec);
	return (sh_num_flags(&sum, now, z, '\0'));
}
