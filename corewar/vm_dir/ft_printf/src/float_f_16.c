/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_f_16.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 19:47:03 by omartyno          #+#    #+#             */
/*   Updated: 2016/12/29 20:57:08 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int		float_f_16(long double z, t_param *now)
{
	char	*sum;

	if (!(z == z) || z == (long double)INFINITY || z == (long double)-INFINITY)
		return (ret_notf(z, now));
	sum = ch_float_16(z, now->prec, (now->type >= 'A' && now->type <= 'Z'));
	if (z < 0 || now->flags[3])
		expand_alt(&sum, (z < 0) ? "-" : "+");
	else if (now->flags[4])
		expand_alt(&sum, " ");
	if (now->flags[0])
		expand_point(&sum, (now->type >= 'A' && now->type <= 'Z') ? 'P' : 'p');
	if (now->width < 0 || ft_strlen(sum) >= (size_t)now->width)
		return (ft_putslen(&sum));
	if (!now->flags[1])
		expand_width(&sum, now->width, now->flags[2], ' ');
	else
		expand_nulls(&sum, now->width, 2);
	return (ft_putslen(&sum));
}
