/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 16:25:12 by omartyno          #+#    #+#             */
/*   Updated: 2016/12/29 20:56:53 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char				*float_join(char **s1, char **s2)
{
	char	*s3;
	size_t	i;
	size_t	j;

	s3 = (char *)malloc(ft_strlen(*s1) + ft_strlen(*s2) + 2);
	i = -1;
	while ((*s1)[++i])
		s3[i] = (*s1)[i];
	if (ft_strlen(*s2))
	{
		s3[i++] = '.';
		j = 0;
		while ((*s2)[j])
			s3[i++] = (*s2)[j++];
	}
	s3[i] = '\0';
	my_free((void **)s1);
	my_free((void **)s2);
	*s1 = s3;
	return (*s1);
}

int					get_double_prec(long double x, int base)
{
	int	i;

	i = 0;
	while (x)
	{
		x *= base;
		x -= (long long)x;
		i++;
	}
	return (i);
}

int					get_double_solid(long double x, int base)
{
	int	i;

	i = 0;
	while (x > 1 || x < -1)
	{
		x /= base;
		i++;
	}
	return (i);
}

static int			ret_start(char *ret, long double *x)
{
	int		i;
	char	*ret_s;

	while (*x > ULLONG_MAX)
		*x /= ten_max();
	ret_s = to_base((unsigned long long)*x, 10, 'a');
	i = -1;
	while (ret_s[++i])
		ret[i] = ret_s[i];
	ret[i] = '\0';
	my_free((void **)ret_s);
	*x = *x - (unsigned long long)*x;
	return (i);
}

char				*str_float(long double x)
{
	char		*ret;
	int			size;
	int			i;

	if (!x)
		return (ft_strdup("0"));
	if (x <= ULLONG_MAX)
		return (to_base((unsigned long long)x, 10, 'a'));
	size = get_double_solid(x, 10);
	ret = (char *)malloc(size + 1);
	ret[size] = '\0';
	i = ret_start(ret, &x);
	size -= ft_strlen(ret);
	while (size--)
	{
		x *= 10;
		ret[i++] = '0' + (char)x;
		x = x - (char)x;
	}
	return (ret);
}
