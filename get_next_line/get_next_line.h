/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 09:36:40 by aklimchu          #+#    #+#             */
/*   Updated: 2016/12/17 10:16:15 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32

# include "libft.h"
# include <stdlib.h>
# include <fcntl.h>

typedef struct	s_buff
{
	char		*content;
	char		*pos;
	int			fd;
}				t_buff;

int				get_next_line(const int fd, char **line);

#endif
