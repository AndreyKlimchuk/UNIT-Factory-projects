/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 17:24:07 by aklimchu          #+#    #+#             */
/*   Updated: 2017/01/11 15:37:38 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <inttypes.h>
# include <wchar.h>
# include <unistd.h>

typedef enum	e_bool
{
	FALSE,
	TRUE
}				t_bool;

typedef enum	e_length
{
	def,
	hh,
	h,
	l,
	ll,
	j,
	z
}				t_length;

typedef struct	s_dig_ident
{
	char		spec;
	short		base;
}				t_dig_ident;

typedef struct	s_func_ident
{
	char		spec;
	char		*(*f)(va_list*);
}				t_func_ident;

typedef struct	s_flag_ident
{
	char		sign;
	t_bool		*ptr;
}				t_flag_ident;

typedef struct	s_flags
{
	t_bool		minus;
	t_bool		plus;
	t_bool		hash;
	t_bool		zero;
	t_bool		space;
}				t_flags;

typedef struct	s_params
{
	t_flags		flags;
	t_bool		width;
	int			width_val;
	t_bool		prec;
	int			prec_val;
	t_length	length;
	char		spec;
	int			char_num;
	int			i;
}				t_params;

int				ft_printf(const char *format, ...);
void			get_spec_info(const char *format, va_list *args);
char			*itoa_base(intmax_t n, short base, t_bool *zero);
char			*uitoa_base(uintmax_t n, short base, t_bool *zero);
char			*form_int_num(va_list *args);
unsigned char	*get_wchar(unsigned int wchar);
char			*form_str(va_list *args);
char			*form_char(va_list *args);
int				apply_width(char **str, int size, int padding);
char			*gag(va_list *args);
char			*form_perc(va_list *args);
void			erase_params(void);
int				ft_atoi(const char *str);
int				ft_isdigit(int c);
void			*ft_memalloc(size_t size);
void			*ft_memrealloc(void **ptr, size_t size);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strcpy(char *dst, const char *src);
size_t			ft_strlen(const char *s);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strnew(size_t size);
char			*ft_strdup(const char *s1);
void			ft_bzero(void *s, size_t n);
void			ft_putnstr(char const *s, size_t n);

extern t_params		g_param;
extern t_func_ident	g_func_arr[];

#endif
