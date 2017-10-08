/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_float_16.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <omartyno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 19:41:25 by omartyno          #+#    #+#             */
/*   Updated: 2016/12/29 10:26:41 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static int			plus_plus_16(char *s)
{
	size_t l;

	if (!(*s))
		return (1);
	l = ft_strlen(s);
	while (l)
	{
		(s[--l])++;
		if (s[l] == ('9' + 1))
		{
			s[l] = 'a';
			break ;
		}
		if (s[l] == ('f' + 1))
			s[l] = '0';
		else
			break ;
	}
	if (s[l] == '0')
		return (1);
	return (0);
}

static double		after_point_16(long double x, long long prec, char *s,
	char a)
{
	int			i;
	long long	int_x;

	i = -1;
	while (++i < prec)
	{
		x *= 16;
		int_x = (long long)(x);
		s[i] = (MOD(int_x) > 9) ? a + MOD(int_x) - 10 : MOD(int_x) + '0';
		x -= int_x;
	}
	return (x);
}

static char			*char_p_plus(int p, char in)
{
	char	*new;
	char	*num;

	new = (char *)malloc(3);
	new[0] = in;
	new[1] = (p < 0) ? '-' : '+';
	new[2] = '\0';
	num = num_str(MOD(p));
	join_n_free(&new, &num);
	return (new);
}

char				*ch_float_16(long double x, long long prec, int big)
{
	long long	int_x;
	char		*s1;
	char		*s2;
	int			i;

	i = get_rank(&x, 16, 2);
	int_x = (long long)x;
	s1 = to_base(MOD(int_x), 16, (big) ? 'A' : 'a');
	x = x - int_x;
	if (prec == -1)
		prec = get_double_prec(x, 16);
	s2 = (char *)malloc(prec + 1);
	s2[prec] = '\0';
	x = after_point_16(x, prec, s2, (big) ? 'A' : 'a');
	if (x >= 0.5)
		if (plus_plus_16(s2))
			if (plus_plus_16(s1))
				expand_alt(&s1, "1");
	if (prec)
		float_join(&s1, &s2);
	expand_alt(&s1, (big) ? "0X" : "0x");
	s2 = char_p_plus(i, (big) ? 'P' : 'p');
	join_n_free(&s1, &s2);
	return (s1);
}
