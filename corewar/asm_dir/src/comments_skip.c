/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comments_skip.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <omartyno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 19:09:56 by omartyno          #+#    #+#             */
/*   Updated: 2017/03/24 17:44:27 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/asmblr.h"

int		skip_comment(char **line)
{
	size_t		i;
	char		*copy;

	i = 0;
	skip_white_forw(*line, &i);
	if (!(*line)[i] || (*line)[i] == COMMENT_CHAR)
	{
		free(*line);
		return (1);
	}
	i = -1;
	copy = NULL;
	while ((*line)[++i])
		if (((*line)[i]) == COMMENT_CHAR)
		{
			copy = ft_strsub(*line, 0, i);
			break ;
		}
	if (copy)
	{
		free(*line);
		*line = copy;
	}
	return (0);
}
