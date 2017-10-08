/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_num_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 01:55:32 by omartyno          #+#    #+#             */
/*   Updated: 2016/12/31 13:59:31 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static int	much(unsigned long long num, int base)
{
	int much;

	much = 0;
	while (num)
	{
		num /= base;
		much++;
	}
	return (much);
}

char		*to_base(unsigned long long num, int base, char alpha)
{
	char	*ret;
	int		size;

	if (!num)
		return (ft_strdup("0"));
	size = much(num, base);
	ret = (char *)malloc(size + 1);
	ret[size] = '\0';
	while (size--)
	{
		ret[size] = (num % base > 9) ? alpha +
			num % base - 10 : '0' + num % base;
		num /= base;
	}
	return (ret);
}

int			show_num(unsigned long long x, t_param *now, int base,
					const char *alt)
{
	char	*sum;

	sum = to_base(x, base, (now->type >= 'A' && now->type <= 'Z') ? 'A' : 'a');
	if (!(now->prec < 0) && (size_t)now->prec > ft_strlen(sum))
		expand_width(&sum, now->prec, 0, '0');
	if (now->prec == 0 && x == 0)
		ft_freedup(&sum, "");
	if ((x || (now->type != 'x' && now->type != 'X'))
		&& alt[0] && now->flags[0])
		expand_alt(&sum, alt);
	if (now->width < 0 || ft_strlen(sum) >= (size_t)now->width)
		return (ft_putslen(&sum));
	if (!(now->flags[1]))
		expand_width(&sum, now->width, now->flags[2], ' ');
	else
		expand_nulls(&sum, now->width, (now->flags[0]) ? ft_strlen(alt) : 0);
	return (ft_putslen(&sum));
}
