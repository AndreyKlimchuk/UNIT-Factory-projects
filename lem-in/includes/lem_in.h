/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 12:57:26 by aklimchu          #+#    #+#             */
/*   Updated: 2017/02/12 13:45:23 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# define ROOM(node) ((t_room*)((node)->content))
# define MOVE(node) ((t_move*)((node)->content))

# include "libft.h"

typedef struct	s_room
{
	char		*name;
	int			dist;
	int			step;
	int			coord[2];
	int			link_num;
	t_list		*links;
}				t_room;

typedef struct	s_move
{
	int			step_num;
	t_room		*room;
}				t_move;

typedef struct	s_farm
{
	int			unt_num;
	char		*map_desc;
	t_list		*start;
	t_list		*end;
	t_list		*rooms;
}				t_farm;

char			add_link(char *str, t_farm *farm);
char			add_room(char *str, t_farm *farm);
char			**check_link(char *str);
char			**check_room(char *str);
t_room			*search_room(t_list *rooms, char *name);
char			**free_arr(char ***arr);
char			handle_input(t_farm *farm, int fd);
char			search_link(t_list *links, t_room *room);
void			destroy_farm(t_farm **farm);
char			solve(t_farm *farm);
void			increase_dist(t_list **sol, int i);
void			add_to_solution(t_list **sol, int i,
								t_room *curr_pos, int step);
void			sort(t_list **sol, int n);
void			print_solution(t_list **sol, t_farm *farm);

#endif
