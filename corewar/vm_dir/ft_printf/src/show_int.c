/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 00:18:35 by omartyno          #+#    #+#             */
/*   Updated: 2016/12/26 07:27:57 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static int	much(long long x)
{
	int much;

	much = 0;
	while (x)
	{
		x /= 10;
		much++;
	}
	return (much);
}

char		*num_str(long long x)
{
	char	*ret;
	int		size;

	if (!x)
		return (ft_strdup("0"));
	size = much(x);
	ret = (char *)malloc(size + 1);
	ret[size] = '\0';
	size--;
	ret[size] = '0' + ((x < 0) ? -(x % 10) : x % 10);
	x /= 10;
	if (x < 0)
		x *= -1;
	while (size--)
	{
		ret[size] = '0' + x % 10;
		x /= 10;
	}
	return (ret);
}

int			show_int(long long x, t_param *now)
{
	char	*sum;

	sum = num_str(x);
	if (!(now->prec < 0) && (size_t)now->prec > ft_strlen(sum))
		expand_width(&sum, now->prec, 0, '0');
	if (now->prec == 0 && x == 0)
		ft_freedup(&sum, "");
	if (x < 0 || now->flags[3])
		expand_alt(&sum, (x < 0) ? "-" : "+");
	else if (now->flags[4])
		expand_alt(&sum, " ");
	if (now->width < 0 || ft_strlen(sum) >= (size_t)now->width)
		return (ft_putslen(&sum));
	if (!(now->flags[1]))
		expand_width(&sum, now->width, now->flags[2], ' ');
	else
		expand_nulls(&sum, now->width, now->flags[3] || x < 0 || now->flags[4]);
	return (ft_putslen(&sum));
}
