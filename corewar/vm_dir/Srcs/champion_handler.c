/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   champion_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 09:14:01 by aklimchu          #+#    #+#             */
/*   Updated: 2017/03/31 14:34:24 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/vm.h"

int					get_as_le(char *ptr)
{
	char			*str;
	int				i;
	int				num;

	str = ft_strnew(4);
	ptr += 3;
	i = 0;
	while (i < 4)
	{
		str[i++] = *ptr;
		ptr--;
	}
	num = *((int*)str);
	free(str);
	return (num);
}

static void			clear_buff(char *buff)
{
	int				i;

	i = 0;
	while (i < MEM_SIZE)
		buff[i++] = 0;
}

int					choose_next_num(t_state *s)
{
	int				num;
	unsigned int	i;

	num = 1;
	i = 0;
	while (i != s->player_nums)
	{
		i = 0;
		while (i < s->player_nums)
		{
			if (s->players[i].num == num)
			{
				num++;
				break ;
			}
			i++;
		}
	}
	return (num);
}

static unsigned int	get_header(int fd, char *file_name, t_state *s, char *buff)
{
	unsigned int	prog_size;

	clear_buff(buff);
	if (read(fd, buff, PROG_NAME_LENGTH + 4) != PROG_NAME_LENGTH + 4)
		exit_failure("Error: File \"%s\" has invalid content\n", file_name, s);
	s->players[s->player_nums].name = ft_strdup(buff);
	clear_buff(buff);
	if (read(fd, buff, 4) != 4)
		exit_failure("Error: File \"%s\" has invalid content\n",
				file_name, s);
	prog_size = (unsigned int)get_as_le(buff);
	if (prog_size > CHAMP_MAX_SIZE)
		exit_failure("Error: Too big champion in file \"%s\"\n", file_name, s);
	clear_buff(buff);
	if (read(fd, buff, COMMENT_LENGTH + 4) != COMMENT_LENGTH + 4)
		exit_failure("Error: File \"%s\" has invalid content\n", file_name, s);
	s->players[s->player_nums].desc = ft_strdup(buff);
	clear_buff(buff);
	return (prog_size);
}

void				read_champ(int fd, char *file_name, t_state *s, int p_num)
{
	char			buff[MEM_SIZE];
	unsigned int	prog_size;

	prog_size = get_header(fd, file_name, s, buff);
	if (read(fd, buff, MEM_SIZE) != prog_size)
		exit_failure("Error: Invalid champion size in file \"%s\"\n",
				file_name, s);
	s->players[s->player_nums].init_prog_code = ft_memdup(buff, prog_size);
	s->players[s->player_nums].init_prog_size = prog_size;
	s->players[s->player_nums].last_live = 0;
	s->players[s->player_nums].live_in_curr_per = 0;
	s->players[s->player_nums].num = p_num;
	s->player_nums++;
}
