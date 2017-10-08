/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_str_big.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 23:18:06 by omartyno          #+#    #+#             */
/*   Updated: 2016/12/31 16:58:33 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int				show_bigstr(t_param *now, unsigned int *str)
{
	char	*res;
	char	*onech;
	int		ret;
	size_t	i;

	if (!str)
		return (show_string(now, (char *)str));
	i = -1;
	res = malloc(1);
	res[0] = '\0';
	while (str[++i])
	{
		onech = get_wchar(str[i]);
		if (now->prec < 0 || ft_strlen(res) +
			ft_strlen(onech) <= (unsigned long)now->prec)
			join_n_free(&res, &onech);
		else
		{
			my_free((void **)&onech);
			break ;
		}
	}
	ret = show_string(now, res);
	my_free((void **)&res);
	return (ret);
}
