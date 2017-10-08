/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaminsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 16:37:29 by vkaminsk          #+#    #+#             */
/*   Updated: 2017/03/31 15:20:41 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_VM_H
# define COREWAR_VM_H
# define PROC(node) ((t_process*)(node->content))
# define BRIHT_CYCL 40
# define LIVE_BRIHT_CYCL -40

# include "libft.h"
# include "ft_printf.h"
# include "op.h"
# include <ncurses.h>

typedef enum		e_bool
{
	VM_FALSE,
	VM_TRUE
}					t_bool;

typedef	struct		s_arg
{
	unsigned char	type;
	int				val;
}					t_arg;

typedef	struct		s_color_inf
{
	char			p_idx;
	char			bright;
}					t_color_inf;

typedef struct		s_process
{
	int				player_num;
	int				regs[REG_NUMBER];
	unsigned char	*pc;
	unsigned char	curr_opcode;
	t_bool			carry;
	t_bool			skip_bytes;
	size_t			wait_cycles;
	size_t			live_in_curr_per;
}					t_process;

typedef struct		s_player
{
	char			*name;
	char			*desc;
	unsigned char	*init_prog_code;
	unsigned int	init_prog_size;
	int				num;
	size_t			last_live;
	size_t			live_in_curr_per;
}					t_player;

typedef struct		s_state
{
	t_bool			running;
	t_bool			ctd_decreased;
	t_bool			dump;
	t_bool			visu;
	t_bool			hide;
	size_t			cycle_limit;
	size_t			total_cycles;
	size_t			total_live_in_curr_per;
	size_t			process_nums;
	unsigned int	player_nums;
	unsigned int	curr_period_cycles;
	unsigned int	cycle_to_die;
	unsigned int	checks_num;
	unsigned char	arena[MEM_SIZE];
	t_color_inf		color_matrix[MEM_SIZE];
	t_list			*proc;
	t_player		*players;
	unsigned int	delay;
}					t_state;

typedef struct		s_op
{
	char			*name;
	unsigned char	arg_num;
	unsigned char	args_types[3];
	unsigned char	opcode;
	unsigned int	cycles;
	char			*desc;
	t_bool			coding_byte;
	t_bool			small_direct;
}					t_op;

typedef void		(*t_vm_instr)(t_arg *, t_process *, t_state *);

extern t_op			g_op_tab[17];
extern t_vm_instr	g_instr_tab[17];

void				exit_failure(char *format, char *arg, t_state *s);
unsigned char		eval_instruction(t_state *s, t_process *p);
void				run(t_state *s);
void				decrease_cycle_to_die(t_state *s);
t_list				*kill_process(t_list **to_del, t_list **head);
void				announce_winner(t_state *s);
unsigned char		*move_to(int bytes_num, unsigned char *pc,
						unsigned char *mem_start);
int					get_arg_val(t_arg arg, t_process *p,
						unsigned char *arena, char bytes);
void				write_mem(int val, unsigned char *ptr,
						unsigned char *arena);
int					read_mem(unsigned char size, unsigned char *ptr,
						unsigned char *arena);
void				exec_instr(t_process *p, t_state *s);
void				read_champ(int fd, char *file_name, t_state *s, int p_num);
int					choose_next_num(t_state *s);
void				load_champs(t_state *s);
void				handle_args(int argc, char **argv, t_state *s);
void				clear_state(t_state *s);
void				usage(t_state *s);
int					get_as_le(char *ptr);
int					search_player(int p_num, t_state *s);
void				dump(t_state *s);

void				i_xor(t_arg *args, t_process *p, t_state *s);
void				i_zjmp(t_arg *args, t_process *p, t_state *s);
void				i_st(t_arg *args, t_process *p, t_state *s);
void				i_sti(t_arg *args, t_process *p, t_state *s);
void				i_sub(t_arg *args, t_process *p, t_state *s);
void				i_or(t_arg *args, t_process *p, t_state *s);
void				i_add(t_arg *args, t_process *p, t_state *s);
void				i_aff(t_arg *args, t_process *p, t_state *s);
void				i_and(t_arg *args, t_process *p, t_state *s);
void				i_fork(t_arg *args, t_process *p, t_state *s);
void				i_ldi(t_arg *args, t_process *p, t_state *s);
void				i_ld(t_arg *args, t_process *p, t_state *s);
void				i_lfork(t_arg *args, t_process *p, t_state *s);
void				i_live(t_arg *args, t_process *p, t_state *s);
void				i_lld(t_arg *args, t_process *p, t_state *s);
void				i_lldi(t_arg *args, t_process *p, t_state *s);

void				init_visualizer(t_state *s);
void				update_visualizer(t_state *s, int ch);
void				draw_sidebar(t_state *s);
void				draw_arena(t_state *s);
void				end_visu(t_state *s, char dump);

#endif
