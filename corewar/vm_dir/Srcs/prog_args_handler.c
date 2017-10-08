/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prog_args_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 14:16:02 by aklimchu          #+#    #+#             */
/*   Updated: 2017/03/31 15:09:19 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/vm.h"

static t_bool		validate_num(char *str)
{
	int				i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (VM_FALSE);
	while (str[i])
		if (!ft_isdigit(str[i++]))
			return (VM_FALSE);
	return (VM_TRUE);
}

static int			handle_dump_flag(int argc, char **argv, int i, t_state *s)
{
	if (i >= argc - 1)
		usage(s);
	if (!validate_num(argv[i + 1]))
		exit_failure("Invalid number of cycles \"%s\"\n", argv[i + 1], s);
	s->cycle_limit = (size_t)ft_atoll(argv[i + 1]);
	s->dump = VM_TRUE;
	return (2);
}

static int			handle_champ_file(char *file_name, t_state *s, int p_num)
{
	int				fd;
	char			buff[4];

	if (s->player_nums == MAX_PLAYERS)
		exit_failure("Too many champions\n", NULL, s);
	if ((fd = open(file_name, O_RDWR, 777)) == -1)
		exit_failure("Can't read source file \"%s\"\n", file_name, s);
	if (read(fd, buff, 4) != 4)
		exit_failure("Error: File \"%s\" has invalid content\n", file_name, s);
	if (get_as_le(buff) != COREWAR_EXEC_MAGIC)
		exit_failure("Error: File \"%s\" has an invalid header\n",
				file_name, s);
	read_champ(fd, file_name, s, p_num);
	close(fd);
	return (1);
}

static int			handle_pnum_flag(int argc, char **argv, int i, t_state *s)
{
	int				p_num;
	unsigned int	j;

	if (i >= argc - 2)
		usage(s);
	if (!validate_num(argv[i + 1]))
		exit_failure("Invalid player number \"%s\"\n", argv[i + 1], s);
	p_num = (int)ft_atoll(argv[i + 1]);
	j = 0;
	while (j < s->player_nums)
	{
		if (p_num == s->players[j++].num)
			exit_failure("Duplicate in players' numbers\n", NULL, s);
	}
	handle_champ_file(argv[i + 2], s, p_num);
	return (3);
}

void				handle_args(int argc, char **argv, t_state *s)
{
	int				i;

	i = 1;
	while (i < argc)
	{
		if (!ft_strcmp(argv[i], "-dump"))
			i += handle_dump_flag(argc, argv, i, s);
		else if (!ft_strcmp(argv[i], "-n"))
			i += handle_pnum_flag(argc, argv, i, s);
		else if (!ft_strcmp(argv[i], "-v"))
			i += (s->visu = VM_TRUE);
		else if (!ft_strcmp(argv[i], "-hide"))
			i += (s->hide = VM_TRUE);
		else
			i += handle_champ_file(argv[i], s, choose_next_num(s));
	}
	if (!s->player_nums)
		usage(s);
}
