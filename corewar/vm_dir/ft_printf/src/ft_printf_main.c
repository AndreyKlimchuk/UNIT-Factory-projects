/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 20:04:00 by omartyno          #+#    #+#             */
/*   Updated: 2016/12/24 18:42:57 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static t_param		*get_params(const char *src)
{
	t_param	*start;
	t_param *now;
	size_t	i;

	i = 0;
	while (src[i] && src[i] != '%')
		i++;
	if (src[i])
		start = get_on_point(src + i + 1);
	else
		return (NULL);
	i += start->slen;
	now = start;
	while (src[i])
	{
		if (src[i] == '%')
		{
			now->next = get_on_point(src + i + 1);
			i += now->next->slen;
			now = now->next;
		}
		else
			i++;
	}
	return (start);
}

static int			move_n_write(const char **src)
{
	int		i;

	i = 0;
	while ((*src)[i] && (*src)[i] != '%')
		i++;
	write(1, *src, i);
	*src += i;
	return (i);
}

static void			free_params(t_param *now)
{
	t_param *n;

	if (!now)
		return ;
	n = now->next;
	my_free((void **)&now->flags);
	my_free((void **)&now);
	now = n;
	while (n)
	{
		n = now->next;
		my_free((void **)&now->flags);
		my_free((void **)&now);
		now = n;
	}
}

int					ft_printf(const char *src, ...)
{
	int		output;
	t_param	*p_head;
	t_param *now;
	va_list	args;

	if (!src)
		return (0);
	p_head = get_params(src);
	now = p_head;
	va_start(args, src);
	output = 0;
	while (*src)
	{
		if (*src == '%')
		{
			output += show_formatted(now, args, output);
			src += now->slen;
			now = now->next;
		}
		else
			output += move_n_write(&src);
	}
	free_params(p_head);
	va_end(args);
	return (output);
}
