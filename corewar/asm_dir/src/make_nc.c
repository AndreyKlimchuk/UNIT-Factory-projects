/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_nc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <omartyno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 13:09:21 by omartyno          #+#    #+#             */
/*   Updated: 2017/04/01 17:29:31 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/asmblr.h"

void	make_nc(t_header *head, int fd_init, t_prpts *prop)
{
	size_t	i;
	size_t	j;
	char	*name;
	char	*com;

	if (!(name = get_nc(fd_init, TRUE, prop)))
		go_error(NFRMT""COMMAND""NCMD, prop);
	if (!(com = get_nc(fd_init, FALSE, prop)))
		go_error(CFRMT""COMMAND""CCMD, prop);
	j = -1;
	i = 0;
	while (++j <= PROG_NAME_LENGTH + 1)
		if (name[i])
			head->prog_name[j] = name[i++];
		else
			head->prog_name[j] = 0;
	j = -1;
	i = 0;
	while (++j <= COMMENT_LENGTH + 1)
		if (com[i])
			head->comment[j] = com[i++];
		else
			head->comment[j] = 0;
	free(name);
	free(com);
}
