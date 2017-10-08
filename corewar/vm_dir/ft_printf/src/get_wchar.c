/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_wchar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omartyno <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 18:19:45 by omartyno          #+#    #+#             */
/*   Updated: 2016/12/22 23:44:59 by omartyno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static int	byte_num(unsigned int k)
{
	if (k <= 0x7f)
		return (1);
	if (k > 0x7f && k <= 0x7ff)
		return (2);
	if (k > 0x7ff && k <= 0xffff)
		return (3);
	if (k > 0xffff && k <= 0x1fffff)
		return (4);
	return (0);
}

static char	*ascii_char(unsigned int k)
{
	char	*str;

	str = (char *)malloc(2);
	str[1] = '\0';
	str[0] = (char)k;
	return (str);
}

static char	*str_rev(char *str)
{
	size_t	i;
	size_t	len;
	char	swap;

	len = 0;
	while (str[len + 1])
		len++;
	i = 0;
	while (len > i)
	{
		swap = str[i];
		str[i++] = str[len];
		str[len--] = swap;
	}
	return (str);
}

char		*get_wchar(unsigned int k)
{
	unsigned char	*byte_now;
	char			*str;
	int				num;
	int				num_save;

	if (!(num = byte_num(k)) || num == 1)
		return ((!num) ? ft_strdup("") : ascii_char(k));
	num_save = num;
	str = (char *)malloc(num + 1);
	str[num] = '\0';
	while (num--)
	{
		byte_now = (unsigned char *)(&k) + num;
		*byte_now <<= num * 2;
		if (num)
			(*byte_now) |= (*(byte_now - 1)) >> (8 - num * 2);
		*byte_now &= (255 >> 2) | (1 << 7);
		*byte_now |= (1 << 7);
		str[num] = *byte_now;
	}
	byte_now = (unsigned char *)(str) + num_save - 1;
	(*byte_now) &= 255 >> (num_save + 1);
	(*byte_now) |= 255 << (8 - num_save);
	return (str_rev(str));
}
