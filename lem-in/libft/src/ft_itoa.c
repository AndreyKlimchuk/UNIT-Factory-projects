/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklimchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 21:04:32 by aklimchu          #+#    #+#             */
/*   Updated: 2016/11/26 18:05:52 by aklimchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*ft_strbuild(int *arr, int size, int neg)
{
	int				i;
	char			*str;

	if (!(str = (char*)malloc(sizeof(char) * (size + neg + 1))))
		return (NULL);
	i = 0;
	if (neg)
		str[i++] = '-';
	while (i < size + neg)
	{
		str[i] = arr[size - i - 1 + neg] + '0';
		i++;
	}
	str[i] = '\0';
	return (str);
}

char				*ft_itoa(int n)
{
	unsigned int	num;
	int				arr[10];
	int				size;

	num = ((n < 0) ? -n : n);
	size = 0;
	while (num >= 10)
	{
		arr[size++] = num % 10;
		num /= 10;
	}
	arr[size++] = num % 10;
	return (ft_strbuild(arr, size, ((n < 0) ? 1 : 0)));
}
