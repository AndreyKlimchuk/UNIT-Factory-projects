/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_e.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 08:53:57 by omartyno          #+#    #+#             */
/*   Updated: 2016/12/29 20:58:35 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static char	*char_e_plus(int p, char in)
{
	char	*new;
	char	*num;
	int		i;

	new = (char *)malloc(3 + ((p < 10) ? 1 : 0));
	i = 0;
	new[i++] = in;
	new[i++] = (p < 0) ? '-' : '+';
	if (p < 10)
		new[i++] = '0';
	new[i] = '\0';
	num = num_str(MOD(p));
	join_n_free(&new, &num);
	return (new);
}

char		*chefloat(long double x, long long prec, char symbol)
{
	char		*s1;
	char		*s2;
	int			i;

	i = get_rank(&x, 10, 10);
	s1 = str_float(x);
	x = dec_part(x);
	s2 = (char *)malloc(prec + 1);
	s2[prec] = '\0';
	x = after_point(x, prec, s2);
	if (x >= 0.5 || x <= -0.5)
		if (plus_plus(s2))
			if (plus_plus(s1))
				expand_alt(&s1, "1");
	float_join(&s1, &s2);
	s2 = char_e_plus(i, symbol);
	join_n_free(&s1, &s2);
	return (s1);
}

int			float_e(long double z, t_param *now)
{
	char	*sum;

	if (!(z == z) || z == (long double)INFINITY || z == (long double)-INFINITY)
		return (ret_notf(z, now));
	if (now->prec == -1)
		now->prec = 6;
	sum = chefloat(z, now->prec, now->type);
	return (sh_num_flags(&sum, now, z, now->type));
}
