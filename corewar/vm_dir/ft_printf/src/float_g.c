/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_g.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 18:06:25 by omartyno          #+#    #+#             */
/*   Updated: 2016/12/29 20:15:49 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <stdio.h>

static int	flomuch(long double x, long long prec)
{
	int	i;

	i = 0;
	while (x && i < prec)
	{
		i++;
		x *= 10;
		x -= (int)x;
	}
	return (i);
}

static char	*chgfloat(long double x, long long prec, int fm)
{
	char		*s1;
	char		*s2;
	long long	pr_nw;

	x = (x < 0) ? -x : x;
	s1 = str_float(x);
	x = dec_part(x);
	pr_nw = prec - ft_strlen(s1);
	if (!fm)
		pr_nw = flomuch(x, pr_nw);
	s2 = (char *)malloc(pr_nw + 1);
	s2[pr_nw] = '\0';
	x = after_point(x, pr_nw, s2);
	if (x >= 0.5 || x <= -0.5)
		if (plus_plus(s2))
			if (plus_plus(s1))
				expand_alt(&s1, "1");
	float_join(&s1, &s2);
	return (s1);
}

int			float_g(long double z, t_param *now)
{
	char	*sum;

	if (!(z == z) || z == (long double)INFINITY || z == (long double)-INFINITY)
		return (ret_notf(z, now));
	if (now->prec == -1)
		now->prec = 6;
	if (get_double_solid(z, 10) <= now->prec)
	{
		sum = chgfloat(z, now->prec, now->flags[0]);
		return (sh_num_flags(&sum, now, z, '\0'));
	}
	else
	{
		sum = chefloat(z, (now->prec) ? now->prec - 1 : now->prec,
					(now->type == 'g') ? 'e' : 'E');
		return (sh_num_flags(&sum, now, z, (now->type == 'g') ? 'e' : 'E'));
	}
}
