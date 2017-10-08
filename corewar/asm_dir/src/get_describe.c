/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_describe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <omartyno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 19:12:57 by omartyno          #+#    #+#             */
/*   Updated: 2017/04/02 09:37:09 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/asmblr.h"

char	*last_check(char *line, int fd, t_bool is_name, t_prpts *prop)
{
	char	*ret;

	if (line[0] != '"')
		go_error(((is_name) ? NFRMT""BRACKETS : CFRMT""BRACKETS), prop);
	ret = extract_from_quotes(line, fd, prop, is_name);
	if (ft_strlen(ret) > ((is_name) ? PROG_NAME_LENGTH : COMMENT_LENGTH))
		go_error(((is_name) ? NFRMT""MX_NM_LNGTH : CFRMT""MX_COM_LNGTH), prop);
	return (ret);
}

char	*check_name(int fd, char *line, t_bool is_name, t_prpts *prop)
{
	char	*cmd_str;
	char	*ret;
	int		i;
	size_t	j;

	cmd_str = ft_strdup((is_name) ? NAME_CMD_STRING : COMMENT_CMD_STRING);
	i = -1;
	j = 0;
	while (ft_iswhitespace(line[j]))
		j++;
	while (cmd_str[++i])
		if (cmd_str[i] != line[j + i])
			go_error(((is_name) ? NFRMT""COMMAND""NCMD :
								CFRMT""COMMAND""CCMD), prop);
	free(cmd_str);
	while (ft_iswhitespace(line[j + i]))
		i++;
	ret = last_check(line + j + i, fd, is_name, prop);
	return (ret);
}

char	*get_nc(int fd, t_bool is_name, t_prpts *prop)
{
	char	*line;
	char	*the_name;
	int		err;

	line = NULL;
	the_name = NULL;
	while ((err = get_next_line(fd, &line, prop)) > 0)
	{
		if (skip_comment(&line))
			continue ;
		the_name = check_name(fd, line, is_name, prop);
		free(line);
		line = NULL;
		break ;
	}
	if (line)
		free(line);
	return (the_name);
}
