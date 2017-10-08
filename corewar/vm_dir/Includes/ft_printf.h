/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <omartyno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 20:07:22 by omartyno          #+#    #+#             */
/*   Updated: 2016/12/31 17:20:53 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define BITS(x) sizeof(x) * 8
# define MOD(x) ((x) ^ ((x) >> (BITS(x) - 1))) - ((x) >> (BITS(x) - 1))
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <limits.h>

typedef struct		s_param
{
	char			type;
	int				lgths;
	char			*flags;
	long long		width;
	int				wis;
	long long		prec;
	int				prs;
	size_t			slen;
	struct s_param	*next;
}					t_param;

enum				e_lgths
{
	hh = 1,
	h,
	j,
	l,
	ll,
	z,
	LL
};

/*
** ft_printf_main.c
*/
int					ft_printf(const char *src, ...);

/*
** skippers.c
*/
size_t				count_chars(const char *src, char ch);
size_t				skip_num(const char *src);
size_t				skip_snn(const char *src);

/*
** get_num_funcs.c
*/
long long			get_num(const char *src);
long long			get_nns(const char *src, long long n);

/*
** get_on_point.c && get_on_point_2.c
*/
size_t				get_type_len(const char *src, t_param *now);
long long			get_prec(const char *src, t_param *now);
long long			get_widt(const char *src, t_param *now);
t_param				*get_on_point(const char *src);
int					get_flags(char c, t_param *now);
int					get_lgths(const char *src, t_param *now);

/*
** get_wchar.c
*/
char				*get_wchar(unsigned int k);

/*
** wchar_to_str.c
*/
char				*join_n_free(char **s1, char **s2);
char				*wchar_to_str(unsigned int **str);

/*
** showf.c
*/
int					show_formatted(t_param *now, va_list args, int out);

/*
** pre_format.c
*/
void				pre_format(t_param *now, va_list args);

/*
** showf_next.c
*/
int					show_formatted_next(t_param *now, va_list args);

/*
** float_f.c
*/
int					float_f(long double z, t_param *now);
int					ret_notf(long double z, t_param *now);
int					sh_num_flags(char **sum, t_param *now,
								long double z, char sym);

/*
** float_e.c
*/
char				*chefloat(long double x, long long prec, char symbol);
int					float_e(long double z, t_param *now);

/*
** float_g.c
*/
int					float_g(long double x, t_param *now);

/*
** char_float.c
*/
char				*ch_float(long double x, long long prec);

/*
** floats_funcs.c & floats_funcs_2.c
*/
char				*float_join(char **s1, char **s2);
int					get_double_prec(long double x, int base);
int					get_double_solid(long double x, int base);
char				*str_float(long double x);

long double			dec_part(long double x);
unsigned long long	ten_max(void);
int					plus_plus(char *s);
long double			after_point(long double x, long long prec, char *s);
int					get_rank(long double *x, int base, int del);

/*
**	float_f_16.c
*/
int					float_f_16(long double z, t_param *now);

/*
** char_float_16.c
*/
char				*ch_float_16(long double x, long long prec, int big);

/*
** show_str.c
*/
int					show_string(t_param *now, char *str);
char				*onechar_str(char c, size_t sz);

/*
** show_str_big.c
*/
int					show_bigstr(t_param *now, unsigned int *str);

/*
** show_num_base.c
*/
int					show_num(unsigned long long x, t_param *now, int base,
						const char *alt);
char				*to_base(unsigned long long num, int base, char alpha);

/*
** show_int.c
*/
char				*num_str(long long x);
int					show_int(long long x, t_param *now);

/*
** expands.c
*/
void				expand_width(char **str, long long wid, char left,
								char with);
void				expand_alt(char **str, const char *s2);
void				expand_nulls(char **str, long long wid, size_t skip);
void				expand_point(char **str, char bef);

/*
** show_char.c
*/
int					show_char(unsigned char c, t_param *now);
int					show_wchar(unsigned int c, t_param *now);

/*
** libft funcs
*/
char				*ft_strdup(const char *s1);
size_t				ft_strlen(const char *s);
void				ft_putstr(const char *s);
char				*ft_freedup(char **s1, const char *s2);
int					ft_putslen(char **s);
int					just_putslen(const char *s);
void				my_free(void **p);
char				*ft_putbits(void *d, size_t ds);

#endif
