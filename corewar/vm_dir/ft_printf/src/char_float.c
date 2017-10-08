/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <omartyno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 15:29:00 by omartyno          #+#    #+#             */
/*   Updated: 2016/12/29 20:52:31 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char				*ch_float(long double x, long long prec)
{
	char		*s1;
	char		*s2;

	x = (x < 0) ? -x : x;
	s1 = str_float(x);
	x = dec_part(x);
	if (prec == -1)
		prec = get_double_prec(x, 10);
	s2 = (char *)malloc(prec + 1);
	s2[prec] = '\0';
	x = after_point(x, prec, s2);
	if (x >= 0.5 || x <= -0.5)
		if (plus_plus(s2))
			if (plus_plus(s1))
				expand_alt(&s1, "1");
	float_join(&s1, &s2);
	return (s1);
}
