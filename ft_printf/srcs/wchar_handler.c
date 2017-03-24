/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 19:12:42 by aklimchu          #+#    #+#             */
/*   Updated: 2017/01/10 15:22:17 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int				count_bytes(unsigned int wchar)
{
	if (wchar > 0x0 && wchar <= 0x7F)
		return (1);
	else if (wchar >= 0x80 && wchar <= 0x7FF)
		return (2);
	else if (wchar >= 0x800 && wchar <= 0xFFFF)
		return (3);
	else if (wchar >= 0x10000 && wchar <= 0x1FFFFF)
		return (4);
	else
		return (0);
}

static unsigned char	*ascii_str(unsigned int wchar)
{
	unsigned char		*str;

	str = (unsigned char*)ft_strnew(1);
	str[0] = (unsigned char)wchar;
	return (str);
}

unsigned char			*get_wchar(unsigned int wchar)
{
	short				size;
	short				i;
	unsigned char		*str;
	unsigned char		*curr_byte;
	unsigned char		rem;

	curr_byte = (unsigned char*)&wchar;
	if ((size = count_bytes(wchar)) < 2)
		return ((size) ? ascii_str(wchar) : (unsigned char*)ft_strnew(0));
	str = (unsigned char*)ft_strnew(size);
	str[size] = '\0';
	i = 0;
	rem = 0;
	while (i < size)
	{
		str[size - i - 1] |= rem;
		str[size - i - 1] |= (*curr_byte << (i * 2));
		rem = (*curr_byte >> (8 - ++i * 2));
		str[size - i] &= 63;
		str[size - i] |= 128;
		curr_byte++;
	}
	str[0] |= (240 << (4 - size));
	return (str);
}
