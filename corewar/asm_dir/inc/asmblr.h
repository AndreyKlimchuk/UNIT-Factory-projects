/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asmblr.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <omartyno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 17:31:04 by omartyno          #+#    #+#             */
/*   Updated: 2017/04/02 09:47:47 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASMBLR_H
# define ASMBLR_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "./op.h"
# include "../libft/libft.h"
# include <errno.h>
# define BITS(x) sizeof(x) * 8
# define MOD(x) ((x) ^ ((x) >> (BITS(x) - 1))) - ((x) >> (BITS(x) - 1))
# define PROG_START (PROG_NAME_LENGTH + COMMENT_LENGTH + sizeof(int) * 4)

/*
** get_next_line part
*/
# define BUFF_SIZE 10000

typedef enum		e_bool
{
	FALSE,
	TRUE
}					t_bool;

typedef struct		s_arg
{
	int				value;
	unsigned char	type;
}					t_arg;

typedef struct		s_op
{
	char			*name;
	int				arg_num;
	unsigned char	arg_types[3];
	int				opcode;
	int				cycles;
	char			*desc;
	t_bool			coding_byte;
	t_bool			small_label;
}					t_op;

typedef struct		s_arg_str
{
	char			*str;
	int				size;
}					t_arg_str;

typedef struct		s_ophsh
{
	t_op			*value;
	struct s_ophsh	*next;
}					t_ophsh;

extern t_ophsh		*g_op_hash[256];
extern t_op			g_op_tab[17];

typedef struct		s_label
{
	size_t			line;
	char			*key;
	unsigned int	null_place;
	unsigned int	place;
	struct s_label	*next;
	t_bool			small;
}					t_label;

typedef struct		s_entry
{
	char			*key;
	unsigned int	value;
	struct s_entry	*next;
}					t_entry;

typedef struct		s_prpts
{
	t_entry			**table;
	int				size;
	t_label			*head;
	unsigned int	bc;
	size_t			i;
	size_t			str_now;
	size_t			str_byte;
	t_op			*now;
}					t_prpts;

/*
** get_next_line struct and def
*/
int					get_next_line(int fd, char **line, t_prpts *prop);

typedef struct		s_buffer
{
	int					d;
	char				*content;
	char				*start;
	struct s_buffer		*next;
}					t_buffer;

/*
** errors texts
*/
# define NFRMT "Name not well formatted\n"
# define CFRMT "Comment not well formatted\n"
# define BRACKETS "Perhaps you forgot to put it in brackets?\n"
# define MX_NM_LNGTH "Check size. Max name length is 128\n"
# define MX_COM_LNGTH "Check size. Max comment length is 128\n"
# define COMMAND "Perhaps you forgot to use command string? Use "
# define NCMD ".name\n"
# define CCMD ".comment\n"

char				*get_nc(int fd, t_bool is_name, t_prpts	*prop);
char				*extract_from_quotes(char *start, int fd,
								t_prpts *prop, t_bool is_name);

int					skip_comment(char **line);

/*
** white chars handling
*/
int					white_string(const char *str);
void				skip_white_forw(char *str, size_t *i);
void				skip_white_back(char *str, size_t *i);

/*
** error handling
*/
void				go_error(const char *err_message, t_prpts *prop);
void				label_err(t_label *lbl);
void				change_unlink_name(char *name);

/*
** hash table
*/
t_entry				**init_table(int size);
int					get_index(char *key, int size);
void				add_value(t_entry **table, int size,
							char *key, unsigned int value);
unsigned int		*get_value(char *key, t_entry **table, int size);
void				free_table(t_entry ***table, int size);

/*
** t_op hash
*/
void				fill_ophash(void);
t_op				*get_ophsh(char *key);
void				add_ophash(t_op *value);
int					get_opind(char *key);

/*
** properties.c
*/
t_prpts				*init_prop(void);
void				free_prop(t_prpts **prop);

char				*new_name(char *init_name, t_bool hidden);
void				make_nc(t_header *head, int fd_init, t_prpts *prop);
void				start_write(t_header head, int fd_init,
									char *name, t_prpts	*prop);
void				write_int_in(int fd, int write, t_bool small);
t_arg_str			*get_cmd_start(int fd_in, t_prpts *prop);
int					is_lblchar(char c);
t_arg_str			*make_cmd(char *line, t_prpts *prop);
t_arg				get_one(char *line, unsigned char type,
										t_prpts *prop, int byte);
void				try_unlink(char *name, t_bool try);

#endif
