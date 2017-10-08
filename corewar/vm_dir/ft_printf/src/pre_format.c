/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 16:22:25 by omartyno          #+#    #+#             */
/*   Updated: 2016/12/31 17:00:05 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <stdio.h>

char		g_nums[] = "diDoOuUxXpaAeEgGfF";

static void	pre_width_n_prec(t_param *now, va_list args, int wid)
{
	if (now->prec <= -2 && now->width <= -2)
	{
		if (now->prec > now->width)
		{
			now->prec = va_arg(args, int);
			if (now->prec < 0 || now->prec > 797599049187327)
				now->prec = -1;
		}
		now->width = wid;
		if (now->prec <= -2)
			now->prec = va_arg(args, int);
	}
	else
	{
		if (now->prec <= -2)
			now->prec = va_arg(args, int);
		if (now->width <= -2)
			now->width = wid;
	}
	if (now->width < 0 || now->width > 797599049187327)
		now->width = -1;
	if (now->prec < 0 || now->prec > 797599049187327)
		now->prec = -1;
}

static int	check_nums(char tp)
{
	int	i;

	i = 0;
	while (g_nums[i] != tp && g_nums[i])
		i++;
	if (g_nums[i])
		return (1);
	return (0);
}

void		pre_format(t_param *now, va_list args)
{
	int		wid;
	int		nl;

	nl = check_nums(now->type);
	while ((now->wis)--)
		wid = va_arg(args, int);
	if (wid < 0)
		now->flags[2] = 1;
	wid = MOD(wid);
	pre_width_n_prec(now, args, wid);
	if (now->flags[2])
		now->flags[1] = 0;
	if (now->prec != -1 && nl)
		now->flags[1] = 0;
	if (now->type == 'p')
		now->flags[0] = 1;
	if (now->type == 'p' || now->type == 'D' ||
		now->type == 'O' || now->type == 'U')
		now->lgths = ll;
	if (!(now->type))
		now->width -= 1;
}
