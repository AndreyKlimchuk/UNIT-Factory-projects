/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_from_quotes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <omartyno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 15:53:39 by aklimchu          #+#    #+#             */
/*   Updated: 2017/03/24 19:03:58 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/asmblr.h"

static char	*error(char **res, char *str, t_prpts *prop)
{
	free(*res);
	go_error(str, prop);
	return (NULL);
}

static char	check_remain(char *closing_quote)
{
	int		i;

	closing_quote++;
	i = -1;
	while (closing_quote[++i])
		if (closing_quote[i] != '\t' && closing_quote[i] != ' ')
			return (0);
	return (1);
}

static char	*find_closing_quote(char *start)
{
	char	*next_quote;

	while ((next_quote = ft_strchr(start, '"')))
	{
		if (*(next_quote - 1) != '\\')
			return (next_quote);
		start = next_quote + 1;
	}
	return (NULL);
}

static void	add_to_res(char **res, char *new_part, size_t size)
{
	char	*new_res;
	int		slash_num;
	size_t	i;
	size_t	j;

	i = -1;
	slash_num = 0;
	while (++i < size)
		if (new_part[i] == '\\' && new_part[i + 1] == '"')
			slash_num++;
	new_res = (char*)malloc(ft_strlen(*res) + size - slash_num + 1);
	i = -1;
	while ((*res)[++i])
		new_res[i] = (*res)[i];
	j = -1;
	while (++j < size)
		if (new_part[j] != '\\' || new_part[j + 1] != '"')
			new_res[i++] = new_part[j];
	new_res[i] = '\0';
	free(*res);
	*res = new_res;
}

char		*extract_from_quotes(char *start, int fd,
							t_prpts *prop, t_bool is_name)
{
	char	*closing_quote;
	char	*res;
	int		i;

	start++;
	res = ft_strnew(0);
	i = 0;
	while (!(closing_quote = find_closing_quote(start)))
	{
		add_to_res(&res, start, ft_strlen(start));
		if (i)
			free(start);
		if (!get_next_line(fd, &start, prop))
		{
			return (error(&res,
				((is_name) ? NFRMT""BRACKETS : CFRMT""BRACKETS), prop));
		}
		i++;
	}
	add_to_res(&res, start, closing_quote - start);
	if (i)
		free(start);
	if (!check_remain(closing_quote))
		return (error(&res, "Garbage after closing quote\n", prop));
	return (res);
}
